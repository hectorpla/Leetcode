class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0, numNodes = 1; // number of nodes for each loop to pop
        
        if ( root ) q.push(root);
        while ( !q.empty() ) {
            int nNext = 0;
            
            level++;
            for ( int i = 0; i < numNodes; i++ ) {
                TreeNode* node = q.front();
                q.pop();
                if ( node->left == NULL && node->right == NULL ) return level;
                else {
                    if ( node->left ) {
                        q.push(node->left);
                        nNext++;
                    }
                    if ( node->right ) {
                        q.push(node->right);
                        nNext++;
                    }
                }
            }
            numNodes = nNext;
        }
        return level;
    }
};