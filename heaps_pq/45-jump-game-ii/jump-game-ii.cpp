class Solution {
public:
    int jump(vector<int>& nums) {

        int ans = 0;
        int minjump = 0;
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        // dp[i] gives the minimum jumps required to reach i

        dp[0] = 0;
        // i think i also have to maintian the maxreach
        int maxreach = 0;
        for(int i = 0  ; i < n; i++){
            //okay so i need to check for each 

            for(int j = 1; j <= nums[i] && i+j< n; j++){
                dp[i+j] = min(dp[i+j], dp[i] + 1);
            }
            
        }

        return dp[n-1];

        return ans;
        
    }
};

// okay need to return the minimum number of jumps
// need to check how many times is maxreach changed

// need to find the sortest path to raech a certain index