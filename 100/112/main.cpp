#include <iostream>
#include <string>
#include <vector>

#include "../../treenode.h"

using namespace std;

class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr &&
            root->val == targetSum)
            return true;

        return hasPathSum(root->right, targetSum - root->val) ||
               hasPathSum(root->left, targetSum - root->val);
    }
};

int main(int argc, char* argv[]) { return 0; }
