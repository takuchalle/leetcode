#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        auto sum = vector<int>();
        for (auto n : nums) {
            auto it = lower_bound(sum.begin(), sum.end(), n);
            if (it != sum.end()) {
                *it = n;
            } else {
                sum.push_back(n);
            }
        }

        return sum.size();
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    {
        auto nums = vector<int>{10, 9, 2, 5, 3, 7, 101, 18};
        cout << s->lengthOfLIS(nums) << endl;
    }
    {
        auto nums = vector<int>{0, 1, 0, 3, 2, 3};
        cout << s->lengthOfLIS(nums) << endl;
    }
    {
        auto nums = vector<int>{7, 7, 7, 7, 7, 7, 7, 7};
        cout << s->lengthOfLIS(nums) << endl;
    }

    delete s;
    return 0;
}
