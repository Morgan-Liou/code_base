#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <sstream>
#include <numeric>
#include <memory>
#include <string>
#include <assert.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(ListNode* next) : val(0), next(next) {};
	ListNode(int x, ListNode* next) : val(x), next(next) {};
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Node {
public:
	int val;
	Node* next;

	Node() {}

	Node(int _val) {
		val = _val;
		next = NULL;
	}

	Node(int _val, Node* _next) {
		val = _val;
		next = _next;
	}
};

/*
*/
class Solution {
public:
	string addBinary(string a, string b) {
		string res;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int n = max(a.size(), b.size());
		int carry = 0;
		for (int i = 0; i < n; ++i) {
			if (i < a.size()) {
				carry += a[i] - '0';
			}
			if (i < b.size()) {
				carry += b[i] - '0';
			}
			res.push_back((carry % 2) ? '1' : '0');
			carry /= 2;
		}
		if (carry) {
			res.push_back('1');
		}

		reverse(res.begin(), res.end());
		return res;
	}
};

int main(){
	Solution s;

	ListNode node(7); ListNode node2(2); ListNode node3(4); ListNode node4(3);
	ListNode* head = &node;
	ListNode* cur = head;
	cur->next = &node2;
	cur = cur->next;
	cur->next = &node3;
	cur = cur->next;
	cur->next = &node4;

	ListNode node_0(5); ListNode node_1(6); ListNode node_2(4);
	ListNode* head_0 = &node_0;
	cur = head_0;
	cur->next = &node_1;
	cur = cur->next;
	cur->next = &node_2;

	cur = s.addTwoNumbers(head, head_0);
	cout << "1";

	getchar();
	return 0;
}