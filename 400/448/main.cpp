#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        auto ans = vector<int>();
        for (size_t i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            nums[idx] = -abs(nums[idx]);
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) ans.push_back(i);
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    vector<int> nums = {4, 3, 2, 7, 8, 3, 2, 1};
    auto ans = s->findDisappearedNumbers(nums);
    for (auto var : ans) {
        cout << var << " ";
    }
    cout << endl;

    return 0;
}
