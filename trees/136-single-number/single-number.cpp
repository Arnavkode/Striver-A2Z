class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int last = nums[0];
        
        for(int i = 1; i < nums.size() ; i++){
            last = last^nums[i];
        }

        int ans;

        for(int i =0 ; i < nums.size() ; i++){
            if(nums[i] ^ last == 0) ans = last;
        }
        return ans;
    }
};