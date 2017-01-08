class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        int n = 0;
        
        while (p) {
            n++;
            p = p->next; 
        }
        
        cur = head;
        return helper(0, n - 1);
    }

private:
    ListNode* cur;
    TreeNode* helper(int l, int r) {
        if (l > r) return NULL;
        
        int m = l + (r - l) / 2;
        
        TreeNode* left = helper(l, m - 1);
        TreeNode* ret = new TreeNode(cur->val);
        ret->left = left;
        cur = cur->next;
        ret->right = helper(m + 1, r);
        return ret;
    }
};