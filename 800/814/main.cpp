#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../../treenode.h"

using namespace std;

class Solution {
   public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return nullptr;

        root->right = pruneTree(root->right);
        root->left = pruneTree(root->left);

        if (root->val == 1 || root->right || root->left) {
            return root;
        } else {
            delete root;
            return nullptr;
        }
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
