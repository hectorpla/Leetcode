class Solution { // backtracking solution
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> log;
        
        if ( root ) helper(res, log, root);
        return res;
    }
    
    void helper(vector<string>& paths, vector<int>& log, TreeNode* root) {
        if ( root->left == NULL && root->right == NULL ) {
            log.push_back(root->val);
            string s = "";
            for ( int i = 0; i < log.size() - 1; i++ ) {
                s += to_string(log[i]);
                s += "->";
            }
            s += to_string(log[log.size()-1]);
            paths.push_back(s);
            log.pop_back();
        }
        else {
            log.push_back(root->val);
            if ( root->left ) {
                helper(paths, log, root->left);
            }
            if ( root->right ) {
                helper(paths, log, root->right);
            }
            log.pop_back();
        }
    }
};