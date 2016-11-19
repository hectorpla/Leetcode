class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), start = 0;
        
        while ( n > 1 ) {
            for (int i = 0; i < n - 1; i++) {
                int temp1, temp2;
                
                temp1 = matrix[start+i][start+n-1];
                matrix[start+i][start+n-1] = matrix[start][start+i];
                cout << temp1 << "," << matrix[start+i][start+n-1] << " ";
                
                temp2 = matrix[start+n-1][start+n-1-i];
                matrix[start+n-1][start+n-1-i] = temp1;
                cout << temp2 << "," << matrix[start+n-1][start+n-1-i] << " ";
                
                temp1 = matrix[start+n-1-i][start];
                matrix[start+n-1-i][start] = temp2;
                cout << temp1 << "," << matrix[start+n-1-i][start] << " ";
                
                matrix[start][start+i] = temp1;
                cout << endl;
            }
            cout << endl;
            n -= 2;
            start++;
        }
    }
};