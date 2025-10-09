class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int buy = INT_MAX;
        int maxprofit = 0;

        for(int i =0; i<n; i++){

            if(prices[i] < buy) buy = prices[i];
            else if(prices[i] - buy > maxprofit){
                maxprofit = prices[i] - buy;
            }


        }

        return maxprofit;
    }
};


//for max profit, we need the by prcie to be the minimum as for any amount of sell, the one
//with lower buy would win. second if the buy is not the lowest, we need the highest sell
//if some price is higher than the buy then it will get us profut so if it returns the profit
// we just need ot find out the profit that is maximum

// TIME COMPLEXITY - 0(N)
// SC == O(1)