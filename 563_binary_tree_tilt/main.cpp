#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "../treenode.h"

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   private:
    int findTilt(TreeNode* n, int& sum) {
        if (!n) return 0;

        auto l = findTilt(n->left, sum);
        auto r = findTilt(n->right, sum);
        sum += abs(l - r);

        return n->val + r + l;
    }

   public:
    int findTilt(TreeNode* root) {
        int sum = 0;
        findTilt(root, sum);
        return sum;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    return 0;
}
