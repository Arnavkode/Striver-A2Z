class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        if( n == 1) return nums;

        int odd = 1;
        int even = 0;
        vector<int> temp(n);
        for(int i = 0; i < n ; i++){
            if(nums[i] < 0){ temp[odd] = nums[i]; odd += 2;}
            if(nums[i] >= 0) {temp[even] = nums[i]; even+=2;}
        }
        return temp;
    }
};