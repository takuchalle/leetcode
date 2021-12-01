#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <bit>

using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

class Solution {
public:
	int hammingDistance(int x, int y) {
		return __builtin_popcount(x ^ y);		
    }
};

int
main(int argc, char* argv[]) {
	auto s = unique_ptr<Solution>();

	cout << s->hammingDistance(1, 4) << endl;
	cout << s->hammingDistance(3, 1) << endl;
	
	return 0;
}
