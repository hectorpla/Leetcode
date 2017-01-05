#include "TreeNode.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> res;
        
        helper(res, root, k1, k2);
        return res;
    }
    
private:
    void helper(vector<int>& v, TreeNode* root, int k1, int k2) {
        if (root == NULL) return;
        
        if ( root->val < k1 ) {
            helper(v, root->right, k1, k2);
        }
        else if ( root->val <= k2 ) {
            v.push_back(root->val);
            helper(v, root->left, k1, k2);
            helper(v, root->right, k1, k2);
        }
        else {
            helper(v, root->left, k1, k2);
        }
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    TreeNode* root = createTree(v);
    Solution sol;
    vector<int> res = sol.searchRange(root, 1, 10);

    for (int val : res)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}