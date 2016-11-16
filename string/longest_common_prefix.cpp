class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int m = strs.size();
        if ( !m ) return res;
        int n = strs[0].size();
        
        
        for ( int i = 1; i < m; i++) 
            n = min(int(strs[i].size()), n);
        char ch;
        for ( int j = 0; j < n; j++ ) {
            ch = strs[0][j];
            bool diff = 0; // whether one of the m string diverge at position j 
            
            for ( int i = 1; i < m; i++ ) {
                if ( strs[i][j] != ch ) {
                    diff = 1;
                    break;
                }
            }
            if ( diff ) break;
            res += ch;
        }
        return res;
    }
};