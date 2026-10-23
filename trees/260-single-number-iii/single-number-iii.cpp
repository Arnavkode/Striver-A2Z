class Solution {
public:
    using ll = long long;
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans = {0,0};

        ll diff = nums[0];

        for(int i =1 ; i < nums.size();  i++){
            diff = diff ^ nums[i];
        }

        diff &= -diff;

        for(int num : nums){
            if((diff & num) == 0){
                ans[0] ^= num;
            }else{
                ans[1] ^= num;
            }
        }
        return ans;
        
    }
};