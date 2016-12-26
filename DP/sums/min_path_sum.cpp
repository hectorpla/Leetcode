class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if ( !m ) return 0;
        int n = grid[0].size();
        if ( !n ) return 0;
        vector<vector<int> >SUM(m, vector<int>(n,0));
        
        // base case: the first row and the first column
        SUM[0][0] = grid[0][0];
        for ( int i = 1; i < m; i++ ) SUM[i][0] = grid[i][0] + SUM[i-1][0];
        for ( int i = 1; i < n; i++ ) SUM[0][i] = grid[0][i] + SUM[0][i-1];
        
        for ( int i = 1; i < m; i++ ) {
            for ( int j = 1; j < n; j++ ) {
                SUM[i][j] = min(SUM[i-1][j], SUM[i][j-1]) + grid[i][j];
                // cout << SUM[i][j] << " ";
            }
            // cout << endl;
        }
        
        return SUM[m-1][n-1];
    }
};