#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int arrangeCoins(int n) {
		if(n == 1) return 1;
        size_t i;
		int _n = n;
        for (i = 1; i < _n; i++) {
            if (n >= i) {
                n -= i;
			} else {
				break;
			} 
			/* cout << n << ":" << i << endl; */
        }
        return i - 1;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    cout << s->arrangeCoins(5) << endl;
    cout << s->arrangeCoins(8) << endl;
    cout << s->arrangeCoins(3) << endl;
    cout << s->arrangeCoins(1) << endl;

    return 0;
}
