class Mycompare {
private:
    unordered_map<char, int>* map;
public:
    Mycompare(unordered_map<char, int>* m) { map = m;}
    bool operator()(const char lhs, const char rhs) {
        return (*map)[lhs] < (*map)[rhs];
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int len = s.size();
        
        for(int i = 0; i < len; i++) {
            if ( freq.find(s[i]) == freq.end() ) {
                freq[s[i]] = 1;
            }
            else {
                freq[s[i]]++;
            }
        }
        
        Mycompare mycomp(&freq);
        priority_queue<char, vector<char>, Mycompare> order(mycomp);
        
        for ( auto it : freq ) {
            order.push(it.first);
        }
        
        int pos = 0;
        while ( !order.empty() ) {
            char ch = order.top();
            order.pop();
            for (int i = 0; i < freq[ch]; i++) {
                s[pos++] = ch;
            }
        }
        return s;
    }
};