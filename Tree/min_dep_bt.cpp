class Solution {
public:
    int minDepth(TreeNode* root) { // BFS
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

class Solution {
public:
    int minDepth(TreeNode* root) {
        if ( root == NULL ) return 0;
        
        int minl, minr, m;
        minl = minDepth(root->left);
        minr = minDepth(root->right);
        m = min(minl, minr);
        if ( minl == 0 ) m = minr;
        if ( minr == 0 ) m = minl;
        return 1 + m;
    }
};