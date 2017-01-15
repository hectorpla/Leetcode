class Solution {
public:
    // O(n^3)
    int minCut(string s) {
        vector<int> MC(s.size() + 1, 0); // the min cut for substring that ends at i
        
        MC[0] = -1;
        for (int i = 2; i < s.size() + 1; i++) {
            int temp_min = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (isPalindrome(s, j, i - 1)) 
                    temp_min = min(temp_min, MC[j] + 1);
            }
            MC[i] = temp_min;
        }
        
        // for (int mc : MC) cout << mc << " ";
        return MC[s.size()];
    }
    
private:
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};

class Solution {
public:
    // space O(n^2)
    int minCut(string s) {
        vector<int> MC(s.size() + 1, 0); // the min cut for substring that ends at i
        vector<vector<bool> > VP(s.size(), vector<bool>(s.size(), false));
        
        for (int i = 0; i < s.size(); i++) VP[i][i] = true;
        MC[0] = -1;
        for (int i = 2; i < s.size() + 1; i++) {
            int temp_min = INT_MAX;
            cout << i << " ";
            for (int j = 0; j < i - 1; j++) {
                if ((j + 1 == i - 1 && s[j] == s[i-1]) || (VP[j+1][i-2] && s[j] == s[i-1])) {
                    VP[j][i-1] = true;
                    temp_min = min(temp_min, MC[j] + 1);
                    cout << ".";
                }
            }
            cout << endl;
            MC[i] = temp_min == INT_MAX ? MC[i-1] + 1 : temp_min;
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                cout << VP[i][j] << " ";
            }
            cout << endl;
        }
        
        cout << "--------------------------------------------------------------" << endl;
        for (int mc : MC) cout << mc << " ";
        return MC[s.size()];
    }
};

// optimal: space O(n) 