#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        auto ans = vector<string>();

        auto q = queue<int>();
        for (size_t i = 0; i < nums.size(); i++) {
            if (q.empty()) {
                q.push(nums[i]);
            } else {
                if (q.back() + 1 == nums[i]) {
                    q.push(nums[i]);
                } else {
                    if (q.size() == 1) {
                        ans.push_back(to_string(q.front()));
                    } else {
                        ans.push_back(to_string(q.front()) + "->" +
                                      to_string(q.back()));
                    }
                    q = queue<int>();
                    q.push(nums[i]);
                }
            }
        }

        if (!q.empty()) {
            if (q.size() == 1) {
                ans.push_back(to_string(q.front()));
            } else {
                ans.push_back(to_string(q.front()) + "->" +
                              to_string(q.back()));
            }
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
