#include "ListNode.h"
#include <iostream>

using namespace std;


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        int count = 0;
        
        while ( cur ) {
            count++;
            cur = cur->next;
        }
        
        int half = count / 2;
        ListNode* prev = NULL;
        cur = head;
        // reverse the first half of the linkedlist
        for (int i = 0; i < half; i++) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        ListNode *mid1 = prev, *mid2 = cur;
        cout << "after reverse: " << mid1->val << " " << mid2->val << endl; // notice NULL

        // check reverse
        // ListNode *c = mid1;
        // while ( c ) { cout << c->val << " "; c = c->next; }
        // cout << endl;

        ListNode *p1 = mid1, *p2 = (count % 2 == 0) ? cur : cur->next;

        // check from the middle out
        bool isPlnd = true;
        prev = mid2;       
        for (int i = 0; i < half; i++) {
            cout << "iteration " << i << ": " << p1->val << " " << p2->val << endl;
            ListNode* next = p1->next;
            if ( p1->val != p2->val ) isPlnd = false;
            p1->next = prev;
            prev = p1;
            p1 = next;
            p2 = p2->next;
        }
        
        // post condition
        cur = head;
        while ( cur ) { cout << cur->val << " "; cur = cur->next; } 
        
        return isPlnd;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    sol.isPalindrome(NULL);
    return 0;
}