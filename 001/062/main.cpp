#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> board = vector<vector<int>>(m);
		for (size_t i = 0; i < m; i++) {
			board[i] = vector<int>(n,1);
		}

        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                board[i][j] = board[i - 1][j] + board[i][j - 1];
            }
        }

        return board[m - 1][n - 1];
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

	cout << s->uniquePaths(3, 7) << endl;

    return 0;
}
