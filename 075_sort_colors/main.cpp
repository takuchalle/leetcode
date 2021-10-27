#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
	void sortColors(vector<int>& nums) {
		for (size_t i = 1; i < nums.size(); i++) {
			auto j = i;
			auto pick = nums[i];
			while (j > 0 && nums[j - 1] > pick) {
				nums[j] = nums[j - 1];
				j--;
			}
			nums[j] = pick;
		}
	}
};

int main(int argc, char* argv[]) {
	auto s = std::unique_ptr<Solution>();
	vector<int> v = {2, 0, 2, 1, 1, 0};

	s->sortColors(v);

	for (auto var : v) {
		cout << var << endl;
	}

	return 0;
}
