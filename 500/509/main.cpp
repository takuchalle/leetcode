#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

#if 0
class Solution {
   public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (memo[n] != 0) return memo[n];
        return memo[n] = (fib(n - 1) + fib(n - 2));
    }

    int memo[31];
};
#else
class Solution {
   public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int dp[31] = {0};
        dp[0] = 0;
        dp[1] = 1;

        for (size_t i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
#endif

int main(int argc, char* argv[]) {
    auto s = new Solution();

    cout << s->fib(2) << endl;
    cout << s->fib(3) << endl;
    cout << s->fib(4) << endl;
    cout << s->fib(30) << endl;

    delete s;
    return 0;
}
