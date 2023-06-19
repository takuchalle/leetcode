#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int maxAltitude = 0;

        for (auto v : gain) {
            altitude += v;
            maxAltitude = max(altitude, maxAltitude);
        }

        return altitude;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
