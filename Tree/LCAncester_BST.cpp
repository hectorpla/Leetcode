#include "TreeNode.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	    // p/q-NULL cases
	    int k1 = min(p->val, q->val);
	    int k2 = max(p->val, q->val);
	    
	    TreeNode* cur = root;
	    while ( true ) {
	        if ( cur->val < k1 ) cur = cur->right;
	        else if ( cur->val > k2 ) cur = cur->left;
	        else break;
	    }
	    return cur;
	}
};

int main(int argc, char const *argv[])
{
    int a[] = {6,2,8,0,4,7,9,0,0,3,5};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
	TreeNode* root = createTree(v);
	TreeNode* p = find(root, 3);
	TreeNode* q = find(root, 5);

    Solution sol;
    TreeNode* res = sol.lowestCommonAncestor(root, p, q);
    cout << "result: " << res->val << endl;
    return 0;
}