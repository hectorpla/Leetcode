#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int len = trim(s);
        // cout << "reverseWords: length = " << len << ", original size = " << s.size() << ", diff = "
        // << s.size() - len << endl;
        int to_trim = s.size() - len;
        for (int i = 0; i < to_trim; i++) {
            s.pop_back();
        }
        reverse(s, 0, len);
        cout << "reverseWords:" << endl << s << endl;
        
        int start = 0;
        for (int i = 1; i < len; i++) {
            if ( s[i] == ' ' && s[i-1] != ' ' ) reverse(s, start, i - start);
            if ( s[i] != ' ' && s[i-1] == ' ' ) start = i;
        }
        reverse(s, start, len - start);
    }
    
private:
    int trim(string &s) {
        int pos = -1, start = 0;
        
        while ( s[start] == ' ' ) start++;
        for (int i = start; i < s.size(); i++) {
            if ( s[i] == ' ' && s[pos] == ' ' ) continue;
            s[++pos] = s[i];
        }
        cout << "trim: " << endl << s << "(" << pos << ")" << endl; 

        if ( s[pos] == ' ' ) return pos;
        else return pos + 1;
    }

    void reverse(string &s, int start, int length) {
        for (int i = 0; i < length / 2; i++) {
            char temp = s[start + i];
            s[start + i] = s[start + length - 1 - i];
            s[start + length - 1 - i] = temp;
        }
    }
};


int main(int argc, char const *argv[])
{
    string s = " a";
    Solution sol;
    sol.reverseWords(s);
    cout << s << '#' << endl;

    return 0;
}