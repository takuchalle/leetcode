#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Solution {
   private:
    int searchLeft(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right);
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

		if(left == nums.size() || nums[left] != target) return -1;
        return left;
    }
    int searchRight(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (right - left)/2 + left;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

		if(right < 0 || nums[right] != target) return -1;
        return right;
    }

   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto ans = vector<int>{-1, -1};
        ans[0] = searchLeft(nums, target);
        ans[1] = searchRight(nums, target);

        return ans;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    {
        auto nums = vector<int>{5, 7, 7, 8, 8, 10};
        auto ans = s->searchRange(nums, 8);
        cout << ans[0] << ", " << ans[1] << endl;
    }
    {
        auto nums = vector<int>{5, 7, 7, 8, 8, 10};
        auto ans = s->searchRange(nums, 6);
        cout << ans[0] << ", " << ans[1] << endl;
    }
    {
        auto nums = vector<int>{};
        auto ans = s->searchRange(nums, 0);
        cout << ans[0] << ", " << ans[1] << endl;
    }
    {
        auto nums = vector<int>{1};
        auto ans = s->searchRange(nums, 1);
        cout << ans[0] << ", " << ans[1] << endl;
    }

    delete s;
    return 0;
}
