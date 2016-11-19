/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *cur = head, *tail = NULL;
        bool needPartition = false;
        
        // single element OK
        
        // find tail and the first node to move
        ListNode *first = NULL, *befFirst = NULL;
        while ( cur ) {
            if ( cur->val >= x && !first ) {
                befFirst = tail;
                first = cur;
            }
            tail = cur;
            cur = cur->next;
        }
        if ( first && tail )
            cout << "tail " << tail->val << ", first " << first->val << endl;
        if ( first == NULL || first == tail ) return head;
        
        
        ListNode *prev = befFirst;
        
        // move the first to tail
        cur = first->next;
        if ( befFirst ) befFirst->next = cur;
        if ( first == head ) head = cur;
        insertAtTail(first, tail);
        
        // head might change
        while ( cur != first ) {
            ListNode *it = head;
            while ( it ) {
                cout << it->val << " ";
                it = it->next;
            }
            cout << endl;
            
            if ( cur->val >= x ){
                ListNode *temp = cur;
                cur = cur->next;
                if ( prev ) prev->next = cur;
                if ( temp == head ) head = cur;
                insertAtTail(temp, tail);
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
    
    void insertAtTail(ListNode* node, ListNode*& tail) { // need to change the address of tail
        tail->next = node;
        node->next = NULL;
        tail = node;
    }
};