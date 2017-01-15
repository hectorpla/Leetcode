class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) { // BFS, 22%
        unordered_set<string> dict;
        queue<int> q;
        unordered_set<int> close;
        int end = s.size();
        
        for (string str : wordDict) {
            dict.insert(str);
        }
        q.push(0);
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            
            if (start == end) return true;
            if (close.find(start) != close.end()) continue;
            close.insert(start);
            for (int i = start; i < end; i++) { // begins from start, single alphabet
                string temp = string(s, start, i - start + 1);
                if (dict.find(temp) != dict.end()) {
                    q.push(i + 1);
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) { // DP
        vector<bool> VE(s.size() + 1, false); // valid ends
        unordered_set<string> dict;
        
        for (string w : wordDict) dict.insert(w);
        VE[0] = true;
        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = 0; j < i; j++) {
                if (VE[j]) {
                    string temp(s, j, i - j); // offsets cancelled
                    // cout << temp << endl;
                    if (dict.find(temp) != dict.end()) {
                        VE[i] = true;
                        break;
                    }
                }
            }
        }
        
        // for (bool b : VE) cout << b << " ";
        return VE[s.size()];
    }
};