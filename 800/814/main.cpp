#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../../treenode.h"

using namespace std;

class Solution {
   private:
	   bool pruneNode(TreeNode* node) {
		   if(node == nullptr) return false;
		   bool hasRight = false, hasLeft = false;

		   if(node->right != nullptr) {
			   hasRight = pruneNode(node->right);
			   if(!hasRight) {
				   delete (node->right);
				   node->right = nullptr;
			   }
		   }
			   
		   if(node->left != nullptr) {
			   hasLeft = pruneNode(node->left);
			   if(!hasLeft) {
				   delete (node->left);
				   node->left = nullptr;
			   }
		   }
	
		   return node->val == 1 || hasRight || hasLeft;
	   }

   public:
    TreeNode* pruneTree(TreeNode* root) { return pruneNode(root) ? root : nullptr; }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
