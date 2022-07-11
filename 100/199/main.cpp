#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <deque>
#include "../../treenode.h"

using namespace std;

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ans = vector<int>();
		deque<TreeNode*> q = deque<TreeNode*>();
		if(!root) return ans;

		q.push_back(root);
		while(!q.empty()) {
			ans.push_back(q.back()->val);
			auto size = q.size();
			for (size_t i = 0; i < size; i++) {
				auto node = q.front();
				q.pop_front();	
				if(node->left) q.push_back(node->left);
				if(node->right) q.push_back(node->right);
			}
		}
		
		return ans;
    }
};

int
main(int argc, char* argv[]) {
	auto s = new Solution();

	
	delete s;
	return 0;
}
