#include "TreeLinkNode.h"
#include <iostream>

using namespace std;

class Solution {
public:
    void connect(TreeLinkNode *root) {
        helper(root);
    }
    
    void helper(TreeLinkNode *root) {
        if ( !root ) return;
        if ( root->left ) {
            root->left->next = root->right;
            if ( root->next ) {
                root->right->next = root->next->left;
            }
            helper(root->left);
            helper(root->right);
        }
    }
};

void printLevel(TreeLinkNode* head) {
    while ( head ) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    TreeLinkNode *root = createTree(v);
    printTree(root);
    cout << "------------------------------" << endl;
    Solution sol;
    sol.connect(root);
    TreeLinkNode* head = root;
    while ( head ) {
        printLevel(head);
        head = head->left;
    }
    return 0;
}