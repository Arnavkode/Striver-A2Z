class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
        // for each index were supposed to make a decision about whether to start from this index
        // or take from the last

        int curr = nums[0];
        int best = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            curr = max(curr + nums[i], nums[i]);
            best = max(curr, best);
        }
        return best;
    }
};