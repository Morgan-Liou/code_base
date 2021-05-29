function formatMcode
  try %#ok
    document = matlab.desktop.editor.getActive;
    position = document.Selection;
    document.Text = format(document.Text);
    document.goToPositionInLine(position(1), position(2)) % 还原光标位置
    document.smartIndentContents();
  end
  
function code = format(code)
  code = regexprep(code, {'(\S)[ \f\v\t]+\n', '([^\n])$'}, '$1\n');
  tree = mtree(code, '-comments');
  assert(isempty(tree.mtfind('Kind', 'ERR')))
  
  % a(:) 不替换为 a( : )
  colons = tree.mtfind('Kind', 'COLON');
  colonPos = colons.position();
  colonPos = colonPos(colons.lefttreepos == colons.righttreepos);
  
  % 字符串、注释、数值中的符号以及一元操作符不处理
  exc = tree.mtfind('Kind', 'CHARVECTOR') | tree.mtfind('Kind', 'STRING') | ...
    tree.mtfind('Kind', 'DOUBLE') | tree.mtfind('Kind', 'COMMENT') | ...
    tree.mtfind('Kind', 'UPLUS') | tree.mtfind('Kind', 'UMINUS');
  excPos = [colonPos' ...
    cell2mat(arrayfun(@colon, exc.lefttreepos, exc.righttreepos, 'un', 0)')];
  
  [ops, code, start] = regexp(string(code), ...
    '(\.(\^|\*|/|\\)|<=|>=|==|~=|&&|\|\||\+|\-|\*|\\|/|\^|\||&|<|>|=|,|;|:)', ...
    'match', 'split', 'start');
  idx = ~ismember(start, excPos);
  code(idx) = regexprep(code(idx), '[ \f\r\t\v]+$', '');
  code([false idx]) = regexprep(code([false idx]), '^[ \f\r\t\v]+', '');
  
  ops(idx) = ops(idx) + " ";
  idx = idx & ~ops.startsWith(["," ";"]);
  ops(idx) = " " + ops(idx);
  code = char(strjoin([code; ops ""], ''));
