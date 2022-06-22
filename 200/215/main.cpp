#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

class Solution {
public:
#if 0
	// sort all array approach
    int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), greater<int>());
		return nums[k-1];
    }
#endif
	// priority queue approach
    int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;

		size_t i = 0;
		for (i = 0; i < k; i++) {
			pq.push(nums[i]);
			cout << pq.top() << endl;
		}


		for (; i < nums.size(); i++) {
			if(pq.top() < nums[i]) {
				pq.pop();
				pq.push(nums[i]);
			}
		}

		return pq.top();
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
