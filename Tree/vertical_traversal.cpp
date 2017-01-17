/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct MyComp {
    bool operator()(const pair<int, vector<int>* >& lhs, const pair<int, vector<int>* >& rhs) {
        return lhs.first < rhs.first;
    }  
};

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int> > res;
        unordered_map<int, vector<int>* > cols; // order or unordered???
        queue<pair<TreeNode*, int> > q;
        
        if (root) q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int col = p.second;
            
            if (cols.find(col) == cols.end()) cols[col] = new vector<int>();
            cols[col]->push_back(node->val);
            if (node->left) q.push(make_pair(node->left, col - 1));
            if (node->right) q.push(make_pair(node->right, col + 1));
        }
        vector<pair<int, vector<int>*> > temp;
        MyComp mycomp;
        for (auto c : cols) {
            temp.push_back(c);
        }
        sort(temp.begin(), temp.end(), mycomp);
        for (auto p : temp) {
            res.push_back(*p.second);
        }
        return res;
    }
    
    // dfs: not correct because num in a column not from top to bottom
    void helper(unordered_map<int, vector<int> >& cols, int col, TreeNode* root) {
        if (root == NULL) return;
        
        if (cols.find(col) == cols.end()) {
            cols[col] = vector<int>();
        }
        cols[col].push_back(root->val);
        helper(cols, col - 1, root->left);
        helper(cols, col + 1, root->right);
    }
};