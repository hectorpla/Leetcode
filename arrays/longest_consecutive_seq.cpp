class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> roots;
        unordered_map<int, int> ends;
        unordered_map<int, int> counts;
        int res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if ( roots.find(nums[i]) != roots.end() ) continue;
            int temp, new_begin, new_end;
            
            cout << nums[i] << ": ";
            if ( roots.find(nums[i] - 1) != roots.end() && roots.find(nums[i] + 1) != roots.end() ) {
                cout << "case 1";
                new_begin = roots[nums[i] - 1];
                new_end = ends[nums[i] + 1];
                
                cout << "<" << new_begin << "," << new_end << "> ";
                roots[new_end] = new_begin;
                ends[new_begin]  = new_end;
                temp = counts[new_begin] = counts[new_end] = counts[nums[i] - 1] + 1 + counts[nums[i] + 1];
                cout << "(" << counts[nums[i] - 1] << "," << counts[nums[i] + 1] << ")    ";
            }
            else if ( roots.find(nums[i] - 1) != roots.end() ) {
                cout << "case 2";
                new_begin = roots[nums[i] - 1];
                new_end = nums[i];
                
                roots[nums[i]] = new_begin;
                ends[nums[i]] = nums[i];
                ends[new_begin] = nums[i];
                temp = counts[new_end] = ++counts[new_begin];
            }
            else if ( roots.find(nums[i] + 1) != roots.end() ) {
                cout << "case 3";
                new_begin = nums[i];
                new_end = ends[nums[i] + 1];
                
                roots[nums[i]] = nums[i];
                roots[new_end] = nums[i];
                ends[nums[i]] = new_end;
                temp = counts[new_begin] = ++counts[new_end];
            }
            else {
                cout << "case 4";
                roots[nums[i]] = nums[i];
                ends[nums[i]] = nums[i];
                temp = counts[nums[i]] = 1;
            }
            cout << ", temp = " << temp << endl;
            res = max(res, temp);
        }
        return res;
    }
};