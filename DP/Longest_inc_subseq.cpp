class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> LIS(n, INT_MAX); // the ending num of the sequence with length i + 1
        int maxi = INT_MIN, res = 0;
        
        for (int num : nums) {
            maxi = max(maxi, num);
        }
        for (int i = 0; i < n; i++) {
            for (int lis : LIS) cout << (lis == INT_MAX ? "*" : to_string(lis)) << " ";
            cout << endl;
            int target = nums[i];
            int index = findLastLess(LIS, target, 0, n - 1);
            if (target > LIS[index]) LIS[index+1] = min(LIS[index+1], target);
            else LIS[0] = target; // case where target is less than the min val of the current LIS array
        }
        int index = findLastLess(LIS, maxi, 0, n - 1);
        // bug! what if maxi is INT_MAX: the LIS doesn't end at maxi, then count one more
        return 1 + index + (index < n - 1 && LIS[index+1] == maxi); 
    }
    
private:
    int findLastLess(const vector<int>& nums, int target, int l, int r) {
        while (l < r) { // find the last number less than target, possibly not found (very subtle bug! < vs. <=)
            int m = l + (r - l) / 2 + ((r - l) & 1);
            if (nums[m] < target) l = m;
            else r = m - 1;
        }
        return l;
    }
};