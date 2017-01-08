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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0, dummy_uni;
        helper(root, count, dummy_uni);
        return count;
    }
    
private:
    bool helper(TreeNode* root, int& count, int& uni) {
        if (root == NULL) return true;
        
        int lu, ru;
        bool left, right;
        left = helper(root->left, count, lu);
        right = helper(root->right, count, ru);
        
        // cout << root->val << " " << (!root->left || root->val == lu) << ", " << (!root->right || root->val == ru) << " ";
        if ( left && right && (!root->left || root->val == lu) && (!root->right || root->val == ru) ) {
            // cout << " count!" << endl;
            uni = root->val;
            count++;
            return true;
        }
        else {
            // cout << endl;
            return false;
        }
    }
};