#ifndef SUMS_H
#define SUMS_H

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        len = nums.size();
        if ( len == 0 ) return;

        sums = new int*[len];
        for(int i = 0; i < len; i++) {
            sums[i] = new int[i+1];
        }
        
        sums[0][0] = nums[0];
        for (int i = 1; i < len; i++) {
            sums[i][0] = sums[i-1][0] + nums[i];
            for(int j = 1; j <= i; j++) {
                sums[i][j] = sums[i][j-1] - nums[j-1];
            }
        }
    }

    ~NumArray() {
        if ( len == 0 ) return;
        for (int i = 0; i < len; ++i){
            // cout << "deleting sums[" << i << "]: first element " << sums[i][0] << endl;
            delete[] this->sums[i];
        }
        delete[] sums;
    }

    int sumRange(int j, int i) {
        if ( len == 0 ) return 0; 
        return sums[i][j];
    }
    
private:
    int** sums;
    int len;
};

#endif