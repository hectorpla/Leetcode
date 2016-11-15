/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        cur = root;
        traverseLeftToBottom();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        int ret;
        
        if ( !hasNext() ) return -1;
        TreeNode* tmp = cur;
        cur = st.top();
        st.pop();
        if ( tmp != NULL && tmp->right == cur ) {
            traverseLeftToBottom();
            return next(); // kind of recursive, bad?
        }
        return cur->val;
    }
    
private:
    TreeNode *cur;
    stack<TreeNode*> st;

    void traverseLeftToBottom() {
        while ( cur ) {
            // cout << cur->val << " ";
            if ( cur->right ) st.push(cur->right);
            st.push(cur);
            cur = cur->left;
        }
        // cout << endl;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */