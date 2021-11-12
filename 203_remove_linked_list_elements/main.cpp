#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../listnode.h"

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy = ListNode(0);
        ListNode* a = &dummy;
        for (ListNode* i = head; i != NULL; i = i->next) {
            if (i->val != val) {
                a->next = i;
                a = a->next;
            }
        }
        a->next = nullptr;
        return dummy.next;
    }
};

int main(int argc, char* argv[]) {
    auto s = unique_ptr<Solution>();

    return 0;
}
