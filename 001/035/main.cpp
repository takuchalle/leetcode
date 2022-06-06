#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (right >= left) {
            int mid = (right + left) / 2;

            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    {
        vector<int> nums = {1, 3, 5, 6};
        cout << s->searchInsert(nums, 5) << endl;
    }
    {
        vector<int> nums = {1};
        cout << s->searchInsert(nums, 0) << endl;
    }

    return 0;
}
