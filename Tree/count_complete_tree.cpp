class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode *probe = root;
        int depth = 0;
        
        while (probe->left) {
            depth++;
            probe = probe->left;
        }
        cout << "depth: " << depth << endl;
        return (1 << depth) - 1 + helper(root, 0, depth);
    }
    
    // return # of nodes that are descedent of root, in the last level
    int helper(TreeNode* root, int root_depth, int depth) {
        int ret = 0;
        
        if (root == NULL) return ret;
        if (root_depth == depth) return 1;
        
        TreeNode* probe = root->left;
        int probe_depth = root_depth;
        while (probe) {
            probe_depth++;
            probe = probe->right;
        }
        if (probe_depth < depth) return helper(root->left, root_depth + 1, depth);
        
        ret += 1 << (depth - root_depth - 1);
        return ret + helper(root->right, root_depth + 1, depth);
    }
};