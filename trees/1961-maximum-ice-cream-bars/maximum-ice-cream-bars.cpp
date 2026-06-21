class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int bought = 0;
        for(int i =0 ; i< costs.size(); i++){
            if(coins >= costs[i]){
                coins -= costs[i];
                bought ++;
            }
        }

        return bought;
    }
};

// n ice creams bars
// costs of lenght n
// boy initially has coins to coins to spend
// fuck is counting sort
// boy wants to buy maximum ice creams