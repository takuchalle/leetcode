#include <algorithm>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int max = INT32_MIN;
        int cur = 0;
        for (auto var : nums) {
            cur = std::max(cur + var, var);
            max = std::max(cur, max);
        }
        return max;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    {
        vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        cout << s->maxSubArray(nums) << endl;
    }

    return 0;
}
