class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
       sort(arr.begin(), arr.end());
        int ans = 1;
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= ans + 1) {
                ans++;
            }
        }
        
        return ans;

    }
};

// given an array of positive integers
// first element -> 1
// any teo elments must have a difference of 1
// 