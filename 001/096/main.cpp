#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

class Solution {
public:
	int numTrees(int n, std::vector<int>& memo) {
		if(n == 0) return 0;
		if(n == 1) return 1;
		if(memo[n] != -1) return memo[n];

		int sum = 0;
		for (size_t i = 0; i < n; i++) {
			if(i == 0) {
				sum += numTrees(n - 1, memo);
			}
			else if(i == n - 1) {
				sum += numTrees(n - 1, memo);
			} else {
				sum += numTrees(n - i - 1, memo) * numTrees(n - (n - i), memo);
			}
		}

		memo[n] = sum;
		return sum;
	}

	int numTrees(int n) {
		std::vector<int> memo(n + 1, -1);

		return numTrees(n, memo);
    }
};

int
main(int argc, char* argv[]) {
	auto s = unique_ptr<Solution>();

	cout << s->numTrees(1) << endl;
	cout << s->numTrees(3) << endl;
	
	return 0;
}
