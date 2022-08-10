#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../../treenode.h"

using namespace std;

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }

   private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int offset, int num) {
        if (num == 0) {
            return nullptr;
        }

        int mid = num / 2;
        auto root = new TreeNode(offset + nums[mid]);

        if (mid > 0) {
            root->left = sortedArrayToBST(nums, offset + 1, mid);
        }

        if (mid < num - 1) {
            root->right = sortedArrayToBST(nums, offset + mid + 1, num - mid - 1);
        }

        return root;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    {
        auto nums = vector<int>{-10, -3, 0, 5, 9};
        s->sortedArrayToBST(nums);
    }

    delete s;
    return 0;
}
