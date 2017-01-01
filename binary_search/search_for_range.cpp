class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int l = 0, r = nums.size() - 1;
        if ( r < 0 ) return res;
        int m;
        
        while ( l < r ) {
            m = l + (r - l) / 2;
            if ( nums[m] >= target ) r = m;
            else l = m + 1;
        }
        if ( nums[l] != target ) return res;
        else res[0] = l;
        
        l = 0, r = nums.size() - 1;
        while ( l < r ) {
            m = l + (r - l) / 2;
            if ( (r - l) & 1 ) m++; // ceil the quotient
            if ( nums[m] > target ) r = m - 1;
            else l = m;
        }
        res[1] = l;
        return res;
    }
};