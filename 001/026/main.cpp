#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        int cur = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[cur] != nums[i]) {
                cur += 1;
                nums[cur] = nums[i];
            }
        }

        return cur + 1;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    {
        auto nums = vector<int>{1, 1, 2};
        assert(s->removeDuplicates(nums) == 2);
    }
    {
        auto nums = vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        assert(s->removeDuplicates(nums) == 5);
    }

    delete s;
    return 0;
}
