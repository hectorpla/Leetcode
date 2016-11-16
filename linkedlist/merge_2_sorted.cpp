#include "ListNode.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ( l1 == NULL ) return l2;
        if ( l2 == NULL ) return l1;
        if ( l1->val > l2->val ) return mergeTwoLists(l2, l1);
        
        ListNode *cur1 = l1, *cur2 = l2, *prev1 = NULL;
        
        // insert node in l2 to l1 one by one
        while ( cur2 ) {
            while ( cur1 && cur1->val <= cur2->val ) { // make sure prev1 is never NULL
                prev1 = cur1;
                cur1 = cur1->next;
            }
            ListNode *temp = cur2;
            cur2 = cur2->next;
            insert_after(prev1, temp);
            prev1 = temp; // update prev pointer, otherwise inconsitent
            
            ListNode *p = l1;
            // while ( p ) {
            //     cout << p->val << " ";
            //     p = p->next;
            // }
            // cout << endl;
        }
        
        return l1;
    }
    
private:
    void insert_after(ListNode* n1, ListNode* n2) {
        ListNode* suc = n1->next;
        n1->next = n2;
        n2->next = suc;
    }
};

int main(int argc, char const *argv[])
{
    int a1[] = {1,3};
    vector<int> v1(a1, a1 + sizeof(a1)/sizeof(int));
    int a2[] = {2,4};
    vector<int> v2(a2, a2 + sizeof(a2)/sizeof(int));
    ListNode *l1 = createList(v1, 0);
    ListNode *l2 = createList(v2, 0);

    Solution sol;
    sol.mergeTwoLists(l1, l2);

    return 0;
}