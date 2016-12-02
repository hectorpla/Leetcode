class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> res;
        
        for ( int i = digits.size() - 1; i >= 0; i-- ) {
            int d = digits[i] + carry;
            res.insert(res.begin(), 1, d % 10); // not so efficient
            carry = d / 10;
        }
        if ( carry ) {
            res.insert(res.begin(), 1, 1);
        }
        return res;
    }
};