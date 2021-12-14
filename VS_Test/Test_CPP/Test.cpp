#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {};
//	ListNode(int x) : val(x), next(nullptr) {};
//	//ListNode(ListNode* next) : val(0), next(next) {};
//	ListNode(int x, ListNode* next) : val(x), next(next) {};
//};

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};

class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		sort(courses.begin(), courses.end(), [](const auto& v1, const auto& v2) {
			return v1[1] < v2[1];
		});

		priority_queue<int> q;
		int cur_len = 0;// total duration in current position
		for (const auto& course : courses) {
			int t = course[0], dead_line = course[1];
			if (cur_len + t <= dead_line) {
				cur_len += t;
				q.emplace(t);
			}
			else if(!q.empty() && t < q.top()) {
				cur_len += -q.top() + t;
				q.pop();
				q.emplace(t);
			}
			else {
				//
			}
		}

		return q.size();
	}
};

int main(){
	Solution s;
	s.maxProduct(vector<int> {2,3,-2,4});

	getchar();
	return 0;
}