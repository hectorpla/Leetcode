class Solution {
public:
    // much slower than the optimal solution
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if ( !m ) return false;
        int n = matrix[0].size();
        if ( !n ) return false;
        
        int s = 0, e = m - 1, row = -1;
        while ( s + 1 < e ) {
            int m = s + (e - s) / 2;
            if ( matrix[m][0] <= target ) s = m;
            else e = m - 1;
        }
        if ( matrix[e][0] <= target ) row = e;
        else row = s;
        cout << "row: " << row << endl;
        
        s = 0; e = n - 1;
        while ( s < e ) {
            int m = s + (e - s) / 2;
            if ( matrix[row][m] == target ) return true;
            else if ( matrix[row][m] > target ) e = m - 1;
            else s = m + 1;
        }
        if ( matrix[row][s] == target ) return true; 
        return false;
    }
};