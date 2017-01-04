class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, pivot;
        
        // first find the pivot
        while ( l + 1 < r ) {
            int m = l + (r - l) / 2;
            if ( nums[m] > nums[l] ) l = m;
            else r = m;
        }
        if ( l < r && nums[l] > nums[r] ) pivot = l;
        else return;
        reverse(nums, 0, pivot);
        reverse(nums, pivot + 1, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }
    
    void reverse(vector<int> &nums, int l, int r) {
        int n = r - l + 1;
        for ( int i = 0; i < n / 2; i++ ) {
            int temp = nums[l + i];
            nums[l + i] = nums[l + n - 1 - i];
            nums[l + n - 1 - i] = temp;
        }
    }
};