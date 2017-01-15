class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // one-element case
        // two-element case
        cout << nums1.size() << ", " << nums2.size() << endl;
        int n = nums1.size() + nums2.size();
        if (n & 1) return helper(nums1, 0, nums2, 0, n / 2 + 1);
        else return helper(nums1, 0, nums2, 0, n / 2) / 2 + helper(nums1, 0, nums2, 0, n / 2 + 1) / 2;
    }

private:
    double helper(vector<int>& nums1, int l1, vector<int>& nums2, int l2, int k) {
        cout << "l1 = " << l1 << ", l2 = " << l2 << ", k = " << k << endl;
        if ( k == 1 ) {
            // cout << (int)nums2.size() - 1 << endl;
            if (l1 + 1 > nums1.size()) return nums2[l2];
            if (l2 + 1 > nums2.size()) {
                // cout << nums1[l1] << endl;
                return nums1[l1];
            }
            return min(nums1[l1], nums2[l2]);
        }
        
        int m = k / 2;
        if (l1 + m > nums1.size()) {
            return helper(nums1, l1, nums2, l2 + m, k - m);
        }
        else if (l2 + m > nums2.size()) {
            return helper(nums1, l1 + m, nums2, l2, k - m);
        }
        else if (nums1[l1+m-1] < nums2[l2+m-1]) {
            return helper(nums1, l1 + m, nums2, l2, k - m);
        }
        else {
            return helper(nums1, l1, nums2, l2 + m, k - m);
        }
    }
};