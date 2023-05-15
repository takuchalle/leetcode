#include <iostream>
#include <string>
#include <vector>

#include "../../listnode.h"

using namespace std;

class Solution {
   public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left = nullptr, *right = head;

        auto count = 0;
        int r_count = k * -1;
        for (ListNode* n = head; n != nullptr; n = n->next) {
            if (++count == k) left = n;
            if (++r_count >= 1) right = right->next;
        }

        auto tmp = left->val;
        left->val = right->val;
        right->val = tmp;

        return head;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
