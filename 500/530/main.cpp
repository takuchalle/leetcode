#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

#include "../../treenode.h"

using namespace std;

class Solution {
   public:
    int getMinimumDifference(TreeNode* root) {
        ordering(root);

        const auto n = v.size();
        int minimum = numeric_limits<int>::max();
        for (size_t i = 1; i < n; i++) {
            minimum = min(minimum, v[i] - v[i - 1]);
        }

        return minimum;
    }

   private:
    void ordering(TreeNode* node) {
        if (node == nullptr) return;

        ordering(node->left);
        v.push_back(node->val);
        ordering(node->right);
    }

    vector<int> v;
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
