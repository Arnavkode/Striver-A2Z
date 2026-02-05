class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        cin.tie();
        ios::sync_with_stdio(0);
        int n = nums.size();
        vector<int> res(n);

        for(int i = 0; i< n; i++){
           res[i] = nums[((i + nums[i])%n + n)%n]; //modulo keeps negative sign
            
        }
        return res;
    }
};

// given an interger arrat that reps a circular array
// return a new array
// if found a positive number, move that number, nums[i] steps to the right
// if negative move the current number to the left, nums[i] steps to the left
// if 0 then just let it be 0
