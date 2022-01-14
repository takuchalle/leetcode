#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int myAtoi(string s) {
        auto len = s.length();
        auto pos = 0;
        int64_t ans = 0, tmp = 0;
        auto negative = false;

        // step 1
        while (s[pos] == ' ') pos++;

        // step 2
        if (s[pos] == '+') {
            pos++;
        } else if (s[pos] == '-') {
            negative = true;
            pos++;
        } else {
        }

        // step 3
        // step 3
        while ('0' <= s[pos] && s[pos] <= '9') {
            tmp = tmp * 10 + s[pos] - '0';

            ans = (negative ? -1 * tmp : tmp);
            if (ans < INT32_MIN) {
                ans = INT32_MIN;
                break;
            }
            if (ans > INT32_MAX) {
                ans = INT32_MAX;
                break;
            }
            pos++;
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    cout << s->myAtoi("42") << endl;
    cout << s->myAtoi("-42") << endl;
    cout << s->myAtoi("    -43") << endl;
    cout << s->myAtoi("4194 with words") << endl;
    cout << s->myAtoi("-91283472332") << endl;

    return 0;
}
