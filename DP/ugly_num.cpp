class Solution {
public:
    int nthUglyNumber(int n) { // fail in about 1400
        vector<int> res(n+1,0);
        res[1] = 1;
        
        int mul[3] = {2,3,5};
        int slow = 1;
        
        for ( int i = 2; i <= n; i++ ) {
            while ( res[slow] * 5 <= res[i-1] ) slow++;
            
            int new_num = res[i-1] * 5;
            for ( int j = slow; j < i; j++ ) {
                for ( int k = 0; k < 3; k++ ) {
                    int temp = res[j] * mul[k]; // might overflow
                    // cout << temp << " ";
                    if ( temp > res[i-1]  ) 
                        new_num = min(new_num, temp); 
                }
            }
            res[i] = new_num;
            // cout << endl;
            
        }
        return res[n];
    }
};