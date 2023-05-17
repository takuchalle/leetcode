#include <iostream>
#include <string>
#include <vector>

#include "../../listnode.h"

using namespace std;

class Solution {
   public:
    int pairSum(ListNode* head) {
        vector<int> v;
        for (ListNode* node = head; node != nullptr; node = node->next) {
            v.push_back(node->val);
        }

        int n = v.size();
        int max = 0;
        for (size_t i = 0; i < n / 2; i++) {
            int sum = v[i] + v[n - i - 1];
            if (max < sum) max = sum;
        }

        return max;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
