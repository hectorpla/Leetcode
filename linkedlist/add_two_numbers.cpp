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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = NULL;
        ListNode *cur1 = l1, *cur2 = l2;
        
        int count = 0;
        ListNode* prev = NULL;
        // compute the overlapped part (traverse two lists)
        while ( cur1 && cur2 ) {
            int sum = cur1->val + cur2->val + carry;
            
            appendNewDigit(head, prev, count, sum);
            carry = sum / 10;
            cur1 = cur1->next;
            cur2 = cur2->next;
            count++;
        }
        
        if ( !cur1 && !cur2 ) { // case where two num with same amount of digits
            if ( carry ) {
                prev->next = new ListNode(1);
            }
            return head;
        }
        else {
            ListNode* cur = cur1 ? cur1 : cur2;
            while ( cur ) { // traverse one list
                int sum = cur->val + carry;
                
                appendNewDigit(head, prev, count, sum);
                carry = sum / 10;
                cur = cur->next;
                count++;
            }
            if ( carry ) {
                prev->next = new ListNode(1);
            }
            return head;
        }
    }
    
    void appendNewDigit(ListNode*& head, ListNode*& last, int count, int sum) {
        if ( count == 0 ) {
            head = last = new ListNode(sum % 10);
        }
        else {
            last->next = new ListNode(sum % 10);
            last = last->next;
        }
    }
};