#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n);
        vector<int> ans;

        for (auto& e : edges) {
            visited[e[1]] = true;
        }

        for (size_t i = 0; i < n; i++) {
            if (visited[i]) ans.push_back(i);
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
