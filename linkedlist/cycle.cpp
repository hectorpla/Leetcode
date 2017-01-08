#include <iostream>
#include <set>

#include "ListNode.h"

using namespace std;
 
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         set<int> met;
//         ListNode* cur = head;
        
//         while ( cur ) {
//             if ( met.find(cur->val) == met.end() ) {
//                 met.insert(cur->val);
//             }
//             else return true;
//             cur = head->next;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        while ( fast ) {
            fast = fast->next;
            if ( fast == NULL ) break;
            fast = fast->next;
            slow = slow->next;
            
            if ( slow == fast ) return true;
            cout << fast->val << " , " << slow->val << endl;
        }
        return false;
    }

    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *slow = head, *fast = head;
        
        while (fast) {
            fast = fast->next;
            if (fast) fast = fast->next;
            else return NULL;
            slow = slow->next;
            if (fast == slow) break;
        }
        cout << fast->val << endl;

        slow = head;
        while (true) {
            if (fast == slow) return fast;
            fast = fast->next;
            slow = slow->next;
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    listnode_t* head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = head;
    // head->next->next = new ListNode(3);
    // head->next->next = head;

    Solution sol;
    if (sol.detectCycle(head))
        cout << sol.detectCycle(head)->val << endl;
    else
        cout << "no cycle" << endl;
    return 0;
}