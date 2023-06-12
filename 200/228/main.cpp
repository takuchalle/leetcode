#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        auto ans = vector<string>();

        for (size_t i = 0; i < nums.size(); i++) {
            int j = i;
            while (j + 1 < nums.size() && nums[j] + 1 == nums[j + 1]) {
                j++;
            }

            if (i == j) {
                ans.push_back(to_string(nums[i]));
            } else {
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    {
        auto nums = vector<int>{-1};
        auto res = s->summaryRanges(nums);
        for (auto& v : res) {
            cout << v << endl;
        }
    }

    delete s;
    return 0;
}
