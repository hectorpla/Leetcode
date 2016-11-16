class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cache;
        
        helper(res, cache, n, n);
        return res;
    }
    
    void helper(vector<string>& combs, string& cache, int left, int right) {
        if ( left == 0 && right == 0 ) {
            combs.push_back(cache);
            return;
        }
        
        if ( left ) {
            cache += '(';
            helper(combs,  cache, left - 1, right);
            cache.pop_back(); // c++11 feature, how to make this work in old version
        }
        if ( right > left ) {
            cache += ')';
            helper(combs,  cache, left, right - 1);
            cache.pop_back();
        }
    }
};