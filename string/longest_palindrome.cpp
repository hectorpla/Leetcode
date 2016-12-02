class Solution {
public: // O(n^2) solution
    string longestPalindrome(string s) {
        int len = s.size();
        int center = 0, r = 0;
        int even = 0;
        string res;
        
        if ( !len ) return res;
        for (int i = 0; i < len; i++) {
            int max[2] = { 0, 0 }; // 0 for odd, 1 for even
            
            for ( int odd_even = 0; odd_even < 2; odd_even++ ) {
                while ( i - max[odd_even] >= 0 && i + odd_even + max[odd_even] < len ) {
                    if ( s[i-max[odd_even]] != s[i + odd_even + max[odd_even]] ) break;
                    // cout << s[i-max[odd_even]] << " ";
                    max[odd_even]++;
                }
                // cout << endl;
            }
            for ( int odd_even = 0; odd_even < 2; odd_even++ ) {
                if ( max[odd_even] + odd_even - 1 > r ) {
                    center = i;
                    r = max[odd_even] - 1;
                    even = odd_even;
                }
            }
        }
        // cout << "center = " << center << ", r = " << r << endl;
        
        for ( int i = r; i >= 0; i-- ) res.push_back(s[center-i]);
        if ( even ) res.push_back(s[center+1]);
        for ( int i = 1; i <= r; i++ ) res.push_back(s[center+even+i]);
        return res;
    }
};