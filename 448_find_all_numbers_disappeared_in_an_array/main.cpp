#include <bitset>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        auto ans = vector<int>();
        auto tmp = vector<bool>(n, false);
        for (auto& var : nums) {
            tmp[var - 1] = true;
        }

        for (size_t i = 0; i < n; i++) {
            if (!tmp[i]) ans.push_back(i + 1);
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
