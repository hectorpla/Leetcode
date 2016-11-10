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
        set<ListNode*> met;
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
};

int main(int argc, char const *argv[])
{
    listnode_t* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = head;
    // head->next->next = new ListNode(3);
    // head->next->next = head;

    Solution sol;
    cout << sol.hasCycle(head) << endl;
    return 0;
}