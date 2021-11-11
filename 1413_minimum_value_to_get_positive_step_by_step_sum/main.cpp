#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int minStartValue(vector<int>& nums) {
#if 0
        int startValue = 1;
        while (1) {
            int sum = startValue;
            bool negative = false;
            for (auto var : nums) {
                sum += var;
                if (sum < 1) negative = true;
            }
            if (!negative) break;
            startValue++;
        }

        return startValue;
#endif
        int sum = 0;
        int min = 0;
        for (auto var : nums) {
            sum += var;
            min = std::min(min, sum);
        }
        return -min + 1;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    {
        vector<int> v = {-3, 2, -3, 4, 2};
        cout << s->minStartValue(v) << endl;
    }
    {
        vector<int> v = {1, 2};
        cout << s->minStartValue(v) << endl;
    }
    {
        vector<int> v = {1, -2, -3};
        cout << s->minStartValue(v) << endl;
    }

    return 0;
}
