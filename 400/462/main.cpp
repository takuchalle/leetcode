#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int mid = nums[nums.size() / 2];

		int diff = 0;
		for (auto num : nums) {
			diff += abs(num - mid);
		}

		return diff;
    }
};

int
main(int argc, char* argv[]) {
	auto s = new Solution();

	{
		auto nums = vector<int>{1,2,3};
		cout << s->minMoves2(nums) << endl;
	}

	{
		auto nums = vector<int>{1, 10, 2, 9};
		cout << s->minMoves2(nums) << endl;
	}
	
	delete s;
	return 0;
}
