class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size() - 1);
    }
    
    int helper(vector<int>& nums, int target, int l, int r) {
        if ( l > r ) return l;
        
        int m = l + (r-l) / 2;
        if ( nums[m] == target ) return m;
        else if ( nums[m] < target ) return helper(nums, target, m+1, r);
        else return helper(nums, target, l, m-1);
    }

    // iterative solution (think about two cases: the target is in the array, or not in the array 
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        
        while ( l <= r ) {
            m = l + (r - l) / 2;
            if ( nums[m] == target ) return m;
            else if ( nums[m] < target ) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};

