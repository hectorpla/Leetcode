#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct MyComp {
    bool operator() (const string& lhs, const string& rhs) {
        int p = 0;
        int ls = lhs.size(), rs = rhs.size();

        while (p < ls && p < rs) {
            if (lhs[p] == rhs[p]) p++;
            else return (lhs[p] > rhs[p]);
        }
        if (p == lhs.size() && p == rhs.size()) return false; // return true causes runtime error
        else if (p == lhs.size()) return string(lhs + rhs, ls, rs) > string(rhs + lhs, ls, rs);
        else return string(lhs + rhs, rs, ls) > string(rhs + lhs, rs, ls);
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        MyComp mycomp;
        
        for (int num : nums) {
            stringstream ss;
            string temp;
            
            ss << num;
            ss >> temp;
            strs.push_back(temp);
        }
        sort(strs.begin(), strs.end(), mycomp);
        for (string str : strs) res += str;
        if (res.size() && res[0] == '0') return "0";
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> v = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    cout << sol.largestNumber(v);
    return 0;
}