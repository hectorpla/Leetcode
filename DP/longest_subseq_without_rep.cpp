#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /* 13% DP solution */
    // int lengthOfLongestSubstring(string s) {
    //     int n = s.size();
    //     if ( !n ) return 0;
        
    //     unordered_set<char> cache;
    //     vector<int> STARTS(n + 1, 0);
    //     // STARTS[0] = 1;
        
    //     for ( int i = 1; i <= n; i++ ) {
    //         if ( cache.find(s[i-1]) != cache.end() ) {
    //             int j;
    //             for ( j = STARTS[i-1]; j < i; j++ ) {
    //                 cache.erase(s[j]);
    //                 if ( s[j] == s[i-1] ) break;
    //             }
    //             STARTS[i] = j + 1;
    //             cout << "case 1" << " ";
    //             for ( auto it = cache.begin(); it != cache.end(); ++it ) cout << *it << " ";
    //             cout << endl;
    //         }
    //         else {
    //             STARTS[i] = STARTS[i-1];
    //             cout << "case 2" << " ";
    //             for ( auto it = cache.begin(); it != cache.end(); ++it ) cout << *it << " ";
    //             cout << endl;
    //         }
    //         cache.insert(s[i-1]);
    //     }
        
    //     int res = 0;
    //     for ( int i = 1; i <= n; i++ ) {
    //         res = max(res, i - STARTS[i]);
    //         cout << STARTS[i] << " ";
    //     }
    //     cout << endl;
    //     return res;
    // }

    /* improvement 1 (35%): lazy evaluation */
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if ( !n ) return 0;
        
        unordered_map<char, int> cache;
        vector<int> STARTS(n + 1, 0);

        for ( int i = 1; i <= n; i++ ) {
            if ( cache.find(s[i-1]) != cache.end() && cache[s[i-1]] >= STARTS[i-1] ) { // lazy evaluation
                STARTS[i] = cache[s[i-1]] + 1;
            }
            else {
                STARTS[i] = STARTS[i-1];
            }
            cache[s[i-1]] = i - 1;
        }
        
        int res = 0;
        for ( int i = 1; i <= n; i++ ) {
            res = max(res, i - STARTS[i]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string s = "abcabcbb";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}