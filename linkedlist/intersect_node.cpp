#include "ListNode.h"
#include "iostream"

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *cur, *prev = NULL, *lastA = NULL, *lastB = NULL;
        
        cur = headA;
        while ( cur ) {
            prev = cur;
            cur = cur->next;
            lenA++;
        }
        lastA = prev;
        
        cur = headB;
        while ( cur ) {
            prev = cur;
            cur = cur->next;
            lenB++;
        }
        lastB = prev;
        
        if ( lastA != lastB || lastA == NULL ) return NULL;
        
        ListNode *curA = headA, *curB = headB; 
        if ( lenB > lenA )
            for (int i = 0; i < lenB - lenA; i++ ) curB = curB->next;
        else if ( lenB < lenA )
            for (int i = 0; i < lenA - lenB; i++ ) curA = curA->next;
            
        while ( curA ) {
            if ( curA == curB ) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
	Solution sol;
	listnode_t* headA = new ListNode(5);
    headA->next = new ListNode(4);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(2);
    headA->next->next->next = new ListNode(1);

    listnode_t* headB = new ListNode(3);
    headB->next = new ListNode(2);
    headB->next->next = headA->next->next->next;

    cout << "expected: " << headA->next->next->next << " , result: " << 
    	sol.getIntersectionNode(headA->next, headB->next) << endl;

	return 0;
}