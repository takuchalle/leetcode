#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int findMaximumXOR(vector<int>& nums) {
        auto length = nums.size();
        auto ans = 0;
        for (size_t i = 0; i < length; i++) {
            for (size_t j = i; j < length; j++) {
                auto x = nums[i] ^ nums[j];
                ans = max(ans, x);
            }
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    {
        vector<int> nums = {3, 10, 5, 25, 2, 8};
        cout << s->findMaximumXOR(nums) << endl;
    }

    {
        vector<int> nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
        cout << s->findMaximumXOR(nums) << endl;
    }

    return 0;
}
