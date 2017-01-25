#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dist;
        unordered_set<string> dict;
        
        for (string w : wordList) dict.insert(w);
        if (dict.find(endWord) == dict.end()) return 0;
        dist[endWord] = 0;
        int res = search(beginWord, endWord, dict, dist);
        return res == -1 ? 0 : res + 1;
    }

private: // a DFS search: incorrect solution, not optimal!!!!!!!!!
    int search(string &begin, const string &end, const unordered_set<string>& dict, unordered_map<string, int>& dist) {
        if (dist.find(begin) != dist.end()) return dist[begin];
        
        int ret = -1;
        dist[begin] = -1; // prevent infinite loop, correctness

        for (int i = 0; i < begin.size(); i++) {
            char old = begin[i];
            
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == old) continue;
                begin[i] = c;
                if (dict.find(begin) != dict.end()) {
                    int next = search(begin, end, dict, dist); // the dist to destination from the new string
                    if (next != -1) { // can reach end from the new str
                        if (ret == -1) ret = 1 + next;
                        else ret = min(ret, 1 + next);
                    }
                }
            }
            begin[i] = old;
        }
        dist[begin] = ret;
        cout << begin << ": " << ret << endl;
        return ret;
    }
};

class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        queue<string> q;
        int level = 1;
        
        for (string w : wordList) dict.insert(w);
        if (dict.find(endWord) == dict.end()) return 0;
        
        q.push(beginWord);
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                string s = q.front();
                q.pop();
                
                // dict.erase(s);
                for (int i = 0; i < s.size(); i++) {
                    int old = s[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == old) continue;
                        s[i] = c;
                        if (s == endWord) return level + 1;
                        if (dict.find(s) != dict.end()) {
                            q.push(s);
                            dict.erase(s); // position matters, prevent other path push the word again
                        }
                    }
                    s[i] = old;
                }
            }
            level++;
        }
        return 0;
    }
};

int main(int argc, char const *argv[]) {
    int n = 5;
    string list[5] = {"hot","dot","dog","lot","log"};
    vector<string> wordList;

    for (int i = 0; i < n; i++) {
        wordList.push_back(list[i]);
    }

    Solution sol;
    cout << sol.ladderLength("hit", "cog", wordList) << endl;
    return 0;
}