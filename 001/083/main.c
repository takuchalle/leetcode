#include <stdint.h>
#include <stdio.h>

  
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (head == NULL) { return NULL; }

    struct ListNode *org = head;

    while (head != NULL && head->next != NULL) {
        if (head->val == head->next->val) {
            head->next = head->next->next;         
        } else {
            head = head->next;
        }
    }

    return org;
}


int main(int argc, char* argv[]) {





    return 0;
}