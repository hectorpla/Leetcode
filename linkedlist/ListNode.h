#ifndef LISTNODE_H
#define LISTNODE_H

#include "vector"
#include <iostream>

typedef struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
} listnode_t;

ListNode* createList(const std::vector<int>& vec, int n) {
	// base case: NULL
	if ( n > vec.size() - 1 ) return NULL;
	// recurssion
	ListNode* head = new ListNode(vec[n]);
	head->next = createList(vec, n + 1);
	return head;
}

void deleteListNode(ListNode* head) {
	// base case
	if ( head == NULL ) return;
	
	deleteListNode(head->next);
	delete head;
}

void printList(ListNode* head) {
	ListNode* cur = head;
	while ( cur ) {
		std::cout << cur->val << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
}

#endif

