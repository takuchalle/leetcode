#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), greater<int>());
		return nums[k-1];
    }
};

int
main(int argc, char* argv[]) {
	auto s = new Solution();

	{
		vector<int> nums{3,2,3,1,2,4,5,5,6};
		cout << s->findKthLargest(nums, 4) << endl;
	}
	{
		vector<int> nums{3,2,1,5,6,4};
		cout << s->findKthLargest(nums, 2) << endl;
	}
	
	delete s;
	return 0;
}
