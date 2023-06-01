#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../treenode.h"

using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

class Solution {
private:
	bool isLeaf(TreeNode *node) {
		return node->left == nullptr && node->right == nullptr;
	}

	int parseRightLeaves(TreeNode *node) {
		int sum = 0;
		if(isLeaf(node)) {
			return 0;
		}
		if(node->left != nullptr) sum += parseLeftLeaves(node->left);
		if(node->right != nullptr) sum += parseRightLeaves(node->right);

		return sum;
	}

	int parseLeftLeaves(TreeNode *node) {
		int sum = 0;
		if(isLeaf(node)) {
			return node->val;
		}
		if(node->left != nullptr) sum += parseLeftLeaves(node->left);
		if(node->right != nullptr) sum += parseRightLeaves(node->right);

		return sum;
	}
	
public:
	int sumOfLeftLeaves(TreeNode *root) {
		if(isLeaf(root)) return 0;

		int sum = 0;

		if(root->left != nullptr) sum += parseLeftLeaves(root->left);	
		if(root->right != nullptr) sum += parseRightLeaves(root->right);

		return sum;
	}
};

int
main(int argc, char* argv[]) {
	auto s = unique_ptr<Solution>();
	
	return 0;
}
