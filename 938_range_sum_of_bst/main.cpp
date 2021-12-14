#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../treenode.h"

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;

        int sum = 0;

        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }

        if (root->val > low) {
            sum += rangeSumBST(root->left, low, high);
        }

        if (root->val < high) {
            sum += rangeSumBST(root->right, low, high);
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    return 0;
}
