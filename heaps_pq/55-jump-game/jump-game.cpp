class Solution {
public:
    bool canJump(vector<int>& nums) {
        // will check at each stage, all the options that we might have

        int maxReach = 0;
        int n  = nums.size();

        for(int i = 0; i< n ; i++){
            if(i > maxReach) return false;

            maxReach = max(maxReach, i + nums[i]); 

            if(maxReach >= n )return true;
        }

        return true;

    }
};

// okay jump game
// basically at each step i need to check which jump would make the most sense