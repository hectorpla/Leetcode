#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Solution
{
public:
	int solver(string s) {
		int n = s.size();
    	vector<vector<int> > MP(n + 1, vector<int>(n + 1, 0));

    	for (int i = n - 1; i >= 0; i--) {
    		for (int j = n - 1; j >= i; j--) {
    			int maxPair = MP[i+1][j];

    			for (int k = i + 5; k <= j; k++) {
    				if ((s[i] == 'A' && s[k] == 'U') || (s[i] == 'A' && s[k] == 'U') || 
    					(s[i] == 'C' && s[k] == 'G') || (s[i] == 'G' && s[k] == 'C')) {
    					maxPair = max(maxPair, 1 + MP[i+1][k-1] + MP[k+1][j]);
    				}
    			}
    			MP[i][j] = maxPair;
    		}
    	}

    	cout << "    ";
    	for (int i = 0; i < n; i++) cout << i << " ";
    	cout << endl;
    	int r = 0;
    	for (auto row : MP) {
    		printf("%2d| ", r++);
    		for (int mp : row) cout << mp << " ";
    		cout << endl;
    	}

    	return MP[0][n-1];
	}
};

int main(int argc, char const *argv[]) {
	string s = "CGCCACAUCGGC";
	Solution sol;
	int mp = sol.solver(s);

	cout << endl << endl;
	cout << "The maximum RNA pair of series \"" << s <<  "\" is: " << mp << endl;
	return 0;
}