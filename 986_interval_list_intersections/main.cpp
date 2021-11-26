#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> ans;

        auto firstNum = firstList.size();
        auto secondNum = secondList.size();
        int i = 0, j = 0;
        while (i < firstNum && j < secondNum) {
            int a = max(firstList[i][0], secondList[j][0]);
            int b = min(firstList[i][1], secondList[j][1]);

            if (a <= b) {
                ans.push_back({a, b});
            }

            if (firstList[i][1] < secondList[j][1]) {
                j++;
            } else {
                i++;
            }
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    return 0;
}
