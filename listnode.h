#pragma once
#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static ListNode* array2list(std::vector<int>& array) {
	ListNode dummy = ListNode();
	ListNode* node = &dummy;
    for (auto var : array) {
		node->next = new ListNode(var);
		node = node->next;
    }
	return dummy.next;
}

static void showList(ListNode* node) {
	for (ListNode* n = node; n != nullptr ; n = n->next) {
		std::cout << n->val;
		if(n->next) std::cout << " -> ";
	}
	std::cout << std::endl;
}
