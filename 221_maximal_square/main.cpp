#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        auto m = matrix.size();
        auto n = matrix[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int max = 0;
        for (size_t i = 1; i <= m; i++) {
            for (size_t j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] =
                        1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
                    max = std::max(max, dp[i][j]);
                }
            }
        }
        return max * max;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    return 0;
}
