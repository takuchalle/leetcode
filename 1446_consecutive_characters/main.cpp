#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int maxPower(string s) {
        int max = 1;
        int cnt = 1;
        for (auto c = s.cbegin() + 1; c != s.cend(); c++) {
            if (*(c-1) == *c)
                cnt++;
            else
                cnt = 1;
            max = std::max(max, cnt);
        }

        return max;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    cout << s->maxPower("leetcode") << endl;
    return 0;
}
