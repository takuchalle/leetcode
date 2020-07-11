#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

void printList(struct ListNode* l1) {
	if (l1 == NULL) {
		printf("\n");
		return;
	}
	printf("%d, ", l1->val);
	printList(l1->next);
}

struct ListNode* createList(int list[], int length) {
	struct ListNode head;
	head.next = NULL;
	struct ListNode* cur = &head;

	for (int i = 0; i < length; i++) {
		cur->next = malloc(sizeof(struct ListNode));

		cur = cur->next;

		cur->val = list[i];
	}

	return head.next;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode head;
	head.next = NULL;
	struct ListNode* cur = &head;

	while ((l1 != NULL || l2 != NULL)) {
		if (l1 == NULL) {
			cur->next = l2;
			l2 = l2->next;
		} else if (l2 == NULL) {
			cur->next = l1;
			l1 = l1->next;
		} else {
			if (l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			} else {
				cur->next = l2;
				l2 = l2->next;
			}
		}
        cur = cur->next;
        cur->next = NULL;
	}

	return head.next;
}

int main(int argc, char* argv[]) {
	struct ListNode* head = malloc(sizeof(struct ListNode));

	head->next = NULL;
	int data[] = {1, 2, 4};
	int data2[] = {1};

	struct ListNode* list1 = createList(data, sizeof(data) / sizeof(data[0]));
	struct ListNode* list2 =
	    createList(data2, sizeof(data2) / sizeof(data2[0]));

	printList(list1);
	printList(list2);

	struct ListNode* list3 = mergeTwoLists(list1, list2);

	printList(list3);

	return 0;
}