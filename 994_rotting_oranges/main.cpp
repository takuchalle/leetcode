#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   private:
    void dump(vector<vector<int>>& grid) {
        auto m = grid.size();
        auto n = grid[0].size();

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
				cout << grid[i][j];
            }
			cout << endl;
        }
		cout << endl;
    }

    bool rotten(vector<vector<int>>& grid) {
        auto m = grid.size();
        auto n = grid[0].size();
        bool changed = false;

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] != 2) continue;

                if (i < m - 1 && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 3;
                }
                if (j < n - 1 &&grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 3;
                }
                if (i > 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 3;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 3;
                }
            }
        }
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] == 3) {
                    grid[i][j] = 2;
                    changed = true;
                }
            }
        }

        return changed;
    }

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        auto m = grid.size();
        auto n = grid[0].size();

        uint32_t count = 0;
		while (rotten(grid) == true) {
		//	dump(grid);
			count++;
		}

		uint32_t fresh = 0;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        return fresh ? -1 : count;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

	{
		vector<vector<int>> a = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
		cout << s->orangesRotting(a) << endl;
	}
	{
		vector<vector<int>> a = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
		cout << s->orangesRotting(a) << endl;
	}
	{
		vector<vector<int>> a = {{0, 2}};
		cout << s->orangesRotting(a) << endl;
	}

    return 0;
}
