#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../listnode.h"

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        for (ListNode* i = head; i != nullptr; i = i->next) {
            ans = (ans << 1);
            ans |= i->val;
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    {}

    return 0;
}
