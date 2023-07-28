#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   private:
    int maxDiff(vector<int>& nums, int left, int right, int length) {
        if (left == right) return nums[left];

        auto lefthand = nums[left] - maxDiff(nums, left + 1, right, length - 1);
        auto rightthand =
            nums[right] - maxDiff(nums, left, right - 1, length - 1);

        return max(lefthand, rightthand);
    }

   public:
    bool PredictTheWinner(vector<int>& nums) {
        auto length = nums.size();

        return maxDiff(nums, 0, length - 1, length) >= 0;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    {
        auto nums = vector<int>{1, 5, 2};
        auto expect = false;
        cout << s->PredictTheWinner(nums) << endl;
    }

    {
        auto nums = vector<int>{1, 5, 233, 7};
        auto expect = true;
        cout << s->PredictTheWinner(nums) << endl;
    }

    delete s;
    return 0;
}
