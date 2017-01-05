#include "TreeNode.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root == p) return p;
        if (root == q) return q;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        cout << root->val << ": " << left << ", " << right << endl; 
        if ((left == p && right == q) || (left == q && right == p)) return root;
        else if (left == p || right == p) return p;
        else if (left == q || right == q) return q;
        else return max(left, right);
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {6,2,8,1,4,7,9,0,0,3,5};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    TreeNode* root = createTree(v);
    TreeNode* p = find(root, 9);
    TreeNode* q = find(root, 7);

    Solution sol;
    TreeNode* res = sol.lowestCommonAncestor(root, p, q);
    cout << "result: " << res->val << endl;
    return 0;
}