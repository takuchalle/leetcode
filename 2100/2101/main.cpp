#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        const auto n = bombs.size();
        auto graph = vector<vector<int>>(n, vector<int>());

        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                auto xi = bombs[i][0];
                auto xj = bombs[j][0];
                auto yi = bombs[i][1];
                auto yj = bombs[j][1];
                auto ri = bombs[i][2];

                if (pow(ri, 2) >= pow(xi - xj, 2) + pow(yi - yj, 2)) {
                    graph[i].push_back(j);
                }
            }
        }

        int maximum = 0;
        for (size_t i = 0; i < n; i++) {
            auto visited = vector<bool>(n, false);
            auto ret = dfs(i, graph, visited);
            maximum = max(ret, maximum);
        }

        return maximum;
    }

   private:
    int dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        int count = 1;
        visited[node] = true;
        for (auto var : graph[node]) {
            if (!visited[var]) {
                count += dfs(var, graph, visited);
            }
        }
        return count;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
