#include <bits/stdint-uintn.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		verticalCuts.push_back(w);
		std::sort(verticalCuts.begin(), verticalCuts.end());
		
		uint64_t wMax = verticalCuts[0];
		for (auto i = verticalCuts.begin() + 1; i != verticalCuts.end(); i++) {
			uint64_t diff = *i - *(i-1);	
			wMax = std::max(wMax, diff);
		}

		horizontalCuts.push_back(h);
		std::sort(horizontalCuts.begin(), horizontalCuts.end());

		uint64_t hMax = horizontalCuts[0];
		for (auto i = horizontalCuts.begin() + 1; i != horizontalCuts.end(); i++) {
			uint64_t diff = *i - *(i-1);
			hMax = std::max(hMax, diff);
		}

		return (hMax*wMax)%1000000007;
    }
};


int
main(int argc, char* argv[]) {
	auto s = new Solution();

	{
		auto horizontalCuts = vector<int>{1,2,4};
		auto verticalCuts = vector<int>{1,3};

		cout << s->maxArea(5, 4, horizontalCuts, verticalCuts) << endl;
	}
	{
		auto horizontalCuts = vector<int>{3,1};
		auto verticalCuts = vector<int>{1};

		cout << s->maxArea(5, 4, horizontalCuts, verticalCuts) << endl;
	}
	{
		auto horizontalCuts = vector<int>{3};
		auto verticalCuts = vector<int>{3};

		cout << s->maxArea(5, 4, horizontalCuts, verticalCuts) << endl;
	}
	{
		auto horizontalCuts = vector<int>{2};
		auto verticalCuts = vector<int>{2};

		cout << s->maxArea(1000000000, 1000000000, horizontalCuts, verticalCuts) << endl;
	}
	
	delete s;
	return 0;
}
