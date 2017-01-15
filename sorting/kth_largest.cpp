class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        while (true) {
            int i = l, j = r + 1;
            while (true) {
                while (nums[++i] > nums[l]) {
                    if (i > r) break;
                }
                while (nums[--j] < nums[l]) ;
                if (i > j) break;
                swap(nums[i], nums[j]);
            }
            swap(nums[l], nums[j]);
            
            for (int num : nums) {
                cout << num << " ";
            }
            cout << endl;
            
            if (j == k - 1)  {
                return nums[j];
            }
            else if (j > k - 1) r = j - 1;
            else l = j + 1;
        }
        return 0;
    }
};