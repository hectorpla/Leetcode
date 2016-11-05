class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int len1 = nums1.size(), len2 = nums2.size();
        int p1 = 0, p2 = 0;
        while ( p1 < len1 && p2 < len2 ) {
            if ( nums1[p1] == nums2[p2] ) {
                res.push_back(nums1[p1]);
                p1 = findNext(nums1, p1);
                p2 = findNext(nums2, p2);
            }
            else if ( nums1[p1] < nums2[p2] ) p1 = findNext(nums1, p1);
            else p2 = findNext(nums2, p2);
        }
        return res;
    }
    
private:
    int findNext(vector<int>& nums, int indx) {
        int old = nums[indx], len = nums.size();
        while ( indx < len && nums[indx] == old ) {
            indx++;
        }
        return indx;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> occurs;
        vector<int> res;
        
        for (int i = 0; i < nums1.size(); i++) {
            int tmp = nums1[i];
            if ( occurs.find(tmp) == occurs.end() ) occurs[tmp] = 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            int tmp = nums2[i];
            if ( occurs.find(tmp) != occurs.end() ) occurs[tmp] = 0;
        }
        for ( auto it : occurs ) {
            if ( !it.second )
                res.push_back(it.first);
        }
        
        return res;
    }
};