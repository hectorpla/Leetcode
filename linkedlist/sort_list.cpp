#include "ListNode.h"
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* tail = NULL, *cur = head;
        while ( cur ) {
            tail = cur;
            cur = cur->next;
        }
        return helper(head, tail);
    }
    
private:
    ListNode* helper(ListNode* head, ListNode* tail) {
        if ( !head ) return NULL;
        if ( head == tail ) return head;
        ListNode *m1 = NULL,*m2 = head, *fast = head;
        ListNode *p1 = NULL, *p2 = NULL, *newHead = NULL, *cur = NULL;
        
        while ( fast != tail ) {
            m1 = m2;
            m2 = m2->next;
            fast = fast->next;
            if ( fast != tail ) fast = fast->next;
        }
        m1->next = NULL;
        p1 = helper(head, m1);
        p2 = helper(m2, tail);
        if ( p1 ) newHead = p1;
        if ( p2 ) newHead = p1 ? ( p1->val < p2->val ? p1 : p2 ) : p2;
        while ( p1 || p2 ) {
            if ( !p1 ) {
                moveNode(cur, p2);
            }
            else if ( !p2 ) {
                moveNode(cur,p1);
            }
            else {
                if ( p1->val < p2->val ) moveNode(cur,p1);
                else moveNode(cur,p2);
            }
        }
        return newHead;
    }
    
    void moveNode(ListNode*& to, ListNode*& from) {
        ListNode* temp = from;
        from = from->next;
        temp->next = NULL;
        if ( to ) to->next = temp;
        to = temp;
    }
};

int main(int argc, char const *argv[]) {
    int a[] = {2,1,3};
    std::vector<int> v(a, a + sizeof(a)/sizeof(int));
    Solution sol;
    ListNode* head = createList(v, 0);
    ListNode* newHead = sol.sortList(head);
    printList(newHead);
    return 0;
}