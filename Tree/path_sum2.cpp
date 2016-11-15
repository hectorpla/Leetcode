/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cache;
        int cache_sum = 0;
        
        if ( root ) helper(res, cache, cache_sum, root, sum);
        return res;
    }
    
    void helper(vector<vector<int>>& paths, vector<int>& cache, int& sum, TreeNode* root, int target) {
        // take care of base case, if set to root == NULL, search will be counted even if not a leaf node
        if ( root->left == NULL && root->right == NULL  ) {
            if ( sum + root->val == target ) {
                cache.push_back(root->val);
                paths.push_back(cache);
                cache.pop_back();
            }
            return;
        }
        
        // don't assume positive value!!! as in 1
        // if ( sum + root->val > target ) return;
        
        cache.push_back(root->val);
        sum += root->val;
        if ( root->left )
            helper(paths, cache, sum, root->left, target);
        if ( root->right )
            helper(paths, cache, sum, root->right, target);
        cache.pop_back();
        sum -= root->val;
    }
};