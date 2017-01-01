class Solution {
public:
    int search(vector<int>& nums, int target) {
        if ( nums.empty() ) return -1;
        if ( nums.size() == 1 ) return nums[0] == target ? 0 : -1;
        int l = 0, r = nums.size() - 2, pivot = -1;

        // find the pivot, defined as the position whose value is bigger than that of its next
        if ( nums[l] > nums[l+1] ) pivot = l; // corner: r = l + 1
        if ( nums[r] > nums[r+1] ) pivot = r; // corner: the last second element is the pivot
        while ( l + 1 < r ) { // better put an else
            int m = l + (r - l) / 2;
            if ( nums[m] > nums[m+1] ) {
                pivot = m;
                break;
            }
            else if ( nums[m] > nums[l] ) l = m; // don't +1, will miss pivot
            else r = m; // don't -1, will miss pivot!!! analysize it!!!
        }
        cout << "pivot: " << pivot << endl;
        if ( pivot == -1 ) {
            l = 0;
            r = nums.size();
        }
        else if ( target <= nums[nums.size() - 1] ) {
            l = pivot + 1;
            r = nums.size() - 1;
        }
        else {
            l = 0;
            r = pivot;
        }
        while ( l < r ) {
            int m = l + (r - l) / 2;
            if ( nums[m] == target ) return m;
            else if ( nums[m] < target ) l = m + 1;
            else r = m - 1;
        }
        return nums[l] == target ? l : -1;
    }
};


class Solution {
public: // jiuzhang's solution
    int search(vector<int>& nums, int target) {
        if ( nums.empty() ) return -1;
        int l = 0, r = nums.size() - 1;
        
        while ( l + 1 < r ) {
            int m = l + (r - l) / 2;
            if ( nums[m] == target ) return m;
            if ( nums[m] > nums[l] && nums[m] < nums[r] ) {
                if ( target < nums[m] ) r = m;
                else l = m;
            }
            else if ( nums[m] < nums[l] && nums[m] < nums[r] ) {
                if ( target >= nums[m] && target <= nums[r] ) l = m;
                else r = m;
            }
            else {
                if ( target >= nums[l] && target <= nums[m] ) r = m;
                else l = m;
            }
        }
        cout << "left: " << l << " right: " << r << endl;
        if ( target == nums[l] ) return l;
        else if ( target == nums[r] ) return r;
        else return -1;
    }
};