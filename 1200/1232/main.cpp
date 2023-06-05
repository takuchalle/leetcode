#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        const auto n = coordinates.size();

        double y = (coordinates[1][1] - coordinates[0][1]);
        double x = (coordinates[1][0] - coordinates[0][0]);

        double slope = 1;
        if (x != 0) {
            slope = y / x;
        }

        for (size_t i = 2; i < n; i++) {
            double y = (coordinates[i - 1][1] - coordinates[i][1]);
            double x = (coordinates[i - 1][0] - coordinates[i][0]);

            double slope2 = 1;
            if (x != 0) {
                slope2 = y / x;
            }

            if (slope != slope1) return false;
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
