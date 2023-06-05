#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0;
        int even = 0;
        for (auto var : position) {
            if (var % 2)
                odd++;
            else
                even++;
        }

        return std::min(odd, even);
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    {
        vector<int> position = {2, 2, 2, 3, 3};
        cout << s->minCostToMoveChips(position) << endl;
    }
    {
        vector<int> position = {6, 4, 7, 8, 2, 10, 2, 7, 9, 7};
        cout << s->minCostToMoveChips(position) << endl;
    }

    return 0;
}
