class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;
        vector<vector<bool> > VE(m + 1, vector<bool>(n + 1, false)); 
        // record if some of the combinations of s1, s2 ending at i in s1, and j in s2 validate the first (i+j)th char in s3
        
        VE[0][0] = true;
        for (int i = 1; i < m + 1; i++) VE[i][0] = VE[i-1][0] && s3[i-1] == s1[i-1];
        for (int j = 1; j < n + 1; j++) VE[0][j] = VE[0][j-1] && s3[j-1] == s2[j-1];
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                VE[i][j] = (VE[i-1][j] && s3[i+j-1] == s1[i-1]) || (VE[i][j-1] && s3[i+j-1] == s2[j-1]);
            }
        }
        for (auto row : VE) {
            for (bool ve : row) {
                cout << ve << " ";
            }
            cout << endl;
        }
        return VE[m][n];
    }
};