class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> MM1(n, 0); // rob from the head
        vector<int> MM2(n + 1, 0); // rob from the end
        
        MM1[1] = nums[0];
        for ( int i = 2; i < n; i++ ) {
            MM1[i] = max(MM1[i-1], MM1[i-2] + nums[i-1]); // mind the padding zero on the left
            cout << MM1[i] << " ";
        }
        cout << endl;
        
        MM2[n-1] = nums[n-1];
        for ( int i = n - 2; i > 0; i-- ) {
            MM2[i] = max(MM2[i+1], MM2[i+2] + nums[i]);
            cout << MM2[i] << " ";
        }
        
        return max(MM1[n-2], MM2[1]);
    }
};