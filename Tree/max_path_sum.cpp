#include "TreeNode.h"
#include <iostream>
using namespace std;

#define NINF -2147483648

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int dummy;
        return helper(root, dummy);
    }
    
private:
    // return the max path sum, the greater sum from one side stored in greater
    int helper(TreeNode* root, int& greater) {
        if ( root == NULL ) {
            greater = 0;
            return NINF; // be careful of the negative-value case
        }
        
        int left, right, left_max, right_max;
        left_max = helper(root->left, left);
        right_max = helper(root->right, right);
        
        greater = max(root->val + max(left, right), 0); // if negative, the path sum can be ignored
        return max(root->val + left + right, max(left_max, right_max)); 
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    TreeNode* root = createTree(v);
    Solution sol;

    cout << sol.maxPathSum(root) << endl;
    return 0;
}