class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> ND(n + 1, 0); // number of ways to encode the prefix ending at position i - 2
        
        ND[0] = 1;
        ND[1] = isValid(string(s, 0, 1));
        for (int i = 2; i < n + 1; i++) {
            ND[i] = isValid(string(s, i - 1, 1)) * ND[i-1] + isValid(string(s, i - 2, 2)) * ND[i-2];
        }
        // for (int nd : ND) cout << nd << " ";
        return ND[n];
    }
    
private:
    // given number from 0 to 99 as a string, return 1 if it is valid to be interpreted, 0 otherwise
    int isValid(string s) {
        int num;
        
        if (s.size() == 1) num = s[0] - '0';
        else if (s[0] == '0') return 0;
        else num = (s[0] - '0') * 10 + (s[1] - '0');
        // cout << "isValid: " << num << ": ";
        
        if (num > 0 && num < 27) return 1;
        else return 0;
    }
};

class Solution {
public:
    // space O(1)
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        int prev, pprev;
        
        pprev = 1;
        prev = isValid(string(s, 0, 1));
        for (int i = 1; i < n; i++) {
            int temp = prev * isValid(string(s, i, 1)) + pprev * isValid(string(s, i - 1, 2));
            pprev = prev;
            prev = temp;
            // cout << prev << " ";
        }
        return prev;
    }
    
private:
    // given number from 0 to 99 as a string, return 1 if it is valid to be interpreted, 0 otherwise
    int isValid(string s) {
        int num;
        
        if (s.size() == 1) num = s[0] - '0';
        else if (s[0] == '0') return 0;
        else num = (s[0] - '0') * 10 + (s[1] - '0');

        if (num > 0 && num < 27) return 1;
        else return 0;
    }
};