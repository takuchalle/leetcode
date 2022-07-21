#include <ios>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../../listnode.h"

using namespace std;

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* node = head;
        ListNode* leftnode = head;
        ListNode* rightnode = head;

        int n = right - left + 1;
        for (size_t i = 1;; i++) {
            if (i < left) {
                leftnode = leftnode->next;
            } else {
                ListNode* tmp = leftnode;
                for (size_t w = 1; w < n; w++) {
                    if (tmp->next != nullptr) {
                        int t = tmp->val;
                        tmp->val = tmp->next->val;
                        tmp->next->val = t;
                        tmp = tmp->next;
                    }
                }
                n--;
                if (n == 0) break;
            }
        }
        return head;
    }
};

int main(int argc, char* argv[]) {
    auto s = new Solution();

    {
        auto array = vector<int>{1, 2, 3, 4, 5};
        auto list = array2list(array);
        list = s->reverseBetween(list, 2, 4);
        showList(list);
    }
    {
        auto array = vector<int>{1, 2, 3};
        auto list = array2list(array);
        list = s->reverseBetween(list, 3, 3);
        showList(list);
    }

    delete s;
    return 0;
}
