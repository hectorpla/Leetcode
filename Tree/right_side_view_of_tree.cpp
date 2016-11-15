class Solution {
public:
    vector<int> rightSideView(TreeNode* root) { // BFS
        vector<int> res;
        queue<TreeNode*> q;
        int numPop = 1; // number of nodes to pop
        
        if ( root ) q.push(root);
        while ( !q.empty() ) {
            int n = 0;
            TreeNode* node;
            
            for (int i = 0; i < numPop; i++) {
                node = q.front();
                q.pop();
                if ( node->left ) {
                    q.push(node->left);
                    n++;
                }
                if ( node->right ) {
                    q.push(node->right);
                    n++;
                }
            }
            res.push_back(node->val);
            numPop = n;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) { // DFS
        vector<int> res;
        helper(res, root, 1);
        return res;
    }
    
    void helper(vector<int>& v, TreeNode* root, int depth) {
        if ( !root ) return;
        
        if ( depth > v.size() ) v.push_back(root->val);
        else {
            v[depth-1] = root->val;
        }
        
        if ( root->left ) helper(v, root->left, depth + 1);
        if ( root->right ) helper(v, root->right, depth + 1);
    }
};