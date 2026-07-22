class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size() , 0);
        dp[0] = 0;
        int minprice = prices[0];
        
        for(int i = 1; i < prices.size() ; i++){
            minprice = min (prices[i], minprice);
            dp[i] = max(dp[i-1], prices[i] - minprice);
        }

        return dp[prices.size() -1];
    }
};

// profit should be maximum