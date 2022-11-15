#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "../../treenode.h"

using namespace std;

class Solution {
   public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        size_t left_height = 0, right_height = 0;
        TreeNode *left_node = root, *right_node = root;

        while (right_node) {
            right_height++;
            right_node = right_node->right;
        }

        while (left_node) {
            left_height++;
            left_node = left_node->left;
        }

        if (right_height == left_height) {
            return std::pow(2, left_height) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
