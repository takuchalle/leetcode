#include <iostream>
#include <string>
#include <vector>

#include "../../listnode.h"

using namespace std;

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        ListNode* p = head->next;
        ListNode* prev = nullptr;
        for (ListNode* node = head; node != nullptr; node = node->next) {
            if (node->next) {
                ListNode* next = node->next;
                node->next = next->next;
                next->next = node;
                if (prev != nullptr) {
                    prev->next = next;
                }
                prev = node;
            }
        }

        return p;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    delete s;
    return 0;
}
