
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carried = 0;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* tail = head;
    head->val = 0;
    head->next = NULL;
    struct ListNode* ln1 = l1;
    struct ListNode* ln2 = l2;

    while(1) {
		int data1 = (ln1 != NULL) ? ln1->val : 0;
		int data2 = (ln2 != NULL) ? ln2->val : 0;

		int ans = data1 + data2 + carried;
		if(ans >= 10) {
			carried = 1;
			ans -= 10;
		} else {
			carried = 0;
		}

		tail->val = ans;

		ln1 = (ln1 != NULL) ? ln1->next : NULL;
		ln2 = (ln2 != NULL) ? ln2->next : NULL;

		if(ln1 == NULL && ln2 == NULL && carried == 0 ) {
			break;
		} else {
			tail->next = malloc(sizeof(struct ListNode));
			tail = tail->next;
			tail->next = NULL;
		}
	}

    return head;
}
