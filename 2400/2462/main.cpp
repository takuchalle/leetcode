#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        auto first = priority_queue<int, vector<int>, greater<int>>();
        auto last = priority_queue<int, vector<int>, greater<int>>();

        long long ans = 0;
        int f0 = 0;
        int l0 = costs.size() - 1;
        for (size_t i = 0; i < k; i++) {
            while(first.size() < candidates && f0 <= l0) first.push(costs[f0++]);
            while(last.size() < candidates && f0 <= l0) last.push(costs[l0--]);

            int a = first.empty() ? INT_MAX : first.top();
            int b = last.empty() ? INT_MAX : last.top();

            if(a > b) {
                ans += b;
                last.pop();
            } else {
                ans += a;
                first.pop();
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
