class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // dp with the cost to reach n th step from step 0
        vector<int> dp(n + 1);
        if(n == 1) return costs[0] +1;
        dp[0]=  0;
        dp[1] = costs[0] + 1;
       dp[2] = min(dp[1] + 1, dp[0] + 4) + costs[1];

        for(int i = 3 ; i <= n; i++){
            dp[i] = min({dp[i-1] + 1, dp[i-2] + 4, dp[i-3] + 9}) + costs[i-1];
        }

        return dp[n];
    }
};

// cost form i to j = costs[j] + (j-i)2
