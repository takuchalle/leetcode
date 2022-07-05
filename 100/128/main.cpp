#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		auto s = unordered_set<int>(nums.begin(), nums.end());

		int max_length = 0;
		for (auto num : nums) {
			if(s.count(num - 1)) continue;

			int length = 1;

			while(s.count(num + 1)) {
				length++;
				num++;
			}
			max_length = std::max(length, max_length);
		}

		return max_length;
    }
};

int
main(int argc, char* argv[]) {
	auto s = new Solution();

	{
		auto nums = vector<int>{100, 4, 200, 1, 3, 2};
		cout << s->longestConsecutive(nums) << endl;
	}
	{
		auto nums = vector<int>{0,3,7,2,5,8,4,6,0,1};
		cout << s->longestConsecutive(nums) << endl;
	}
	
	delete s;
	return 0;
}
