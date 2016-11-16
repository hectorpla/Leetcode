class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) { 
        vector<vector<int>> res;
        vector<int> list;
        set<int> added;
        int len = nums.size();
        
        if ( !len ) return res;
        helper(res, list, added, nums);
        return res;
    }
    
    // kind of O(n^n)
    void helper(vector<vector<int>>& pers, vector<int>& cache, set<int>& added, const vector<int>& nums) {
        if ( cache.size() == nums.size() ) {
            pers.push_back(cache);
            return;
        }
        int len = nums.size();
        for ( int i = 0; i < len; i++ ) {
            if ( added.find(nums[i]) == added.end() ) {
                cache.push_back(nums[i]);
                added.insert(nums[i]);
                helper(pers, cache, added, nums);
                cache.pop_back();
                added.erase(nums[i]);
            }
        }
    }
};