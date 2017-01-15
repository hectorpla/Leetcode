struct ListNodeGreater {
    bool operator()(ListNode* lhs, ListNode* rhs) {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, ListNodeGreater> pq;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        for (int i = 0; i < lists.size(); i++ ) {
            if (lists[i]) pq.push(lists[i]);
            else k--;
        }
        while (k) {
            cur->next = pq.top();
            cur = cur->next;
            pq.pop();
            
            if (cur->next) {
                pq.push(cur->next);
            }
            else k--;
        }
        
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};