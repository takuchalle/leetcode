#include <deque>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../../treenode.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> q;

        if (!root) return ans;

        q.push_back(root);
        while (!q.empty()) {
            vector<int> order;

            auto size = q.size();
            for (size_t i = 0; i < size; i++) {
                auto node = q.front();
                order.push_back(node->val);
                q.pop_front();

                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            ans.push_back(order);
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
