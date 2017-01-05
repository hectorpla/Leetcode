class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int dummyMax, dummyMin;
        return helper(root, dummyMax, dummyMin);
    }
    
    bool helper(TreeNode* root, int& vmax, int& vmin) {
        if (root == NULL) {
            vmax = INT_MIN;
            vmin = INT_MAX;
            return true;
        }
        if ( root->left == NULL && root->right == NULL ) {
            vmax = root->val;
            vmin = root->val;
            return true;
        }
        
        int lmax, lmin, rmax, rmin;
        bool isLeftValid = helper(root->left, lmax, lmin);
        bool isRightValid = helper(root->right, rmax, rmin);
        
        vmin = min(lmin, root->val);
        vmax = max(rmax, root->val);
        // cout << root->val << ": " << vmin << ", " << vmax << endl;
        return isLeftValid && isRightValid 
            && (!root->left || lmax < root->val) && (!root->right || root->val < rmin);
    }
};