#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        const auto n = arr.size();
        sort(arr.begin(), arr.end());

        auto diff0 = arr[1] - arr[0];
        for (size_t i = 2; i < n; i++) {
            auto diff = arr[i] - arr[i - 1];
            if (diff0 != diff) return false;
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    {
        vector<int> arr = {3, 5, 1};
        cout << s->canMakeArithmeticProgression(arr) << endl;
    }

    {
        vector<int> arr = {1, 2, 4};
        cout << s->canMakeArithmeticProgression(arr) << endl;
    }
    delete s;
    return 0;
}
