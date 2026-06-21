class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        vector<int> freq(100001);

        for(int i = 0 ;i < costs.size() ; i++){
            freq[costs[i]]++;
        }

        vector<int> sorted(costs.size());
        int sum = 0;
        for(int  i =0 ; i < freq.size() ; i++){
            if(freq[i] == 0) continue;
            sum += freq[i];
            sorted[sum - 1] = i;
        }
        int left = 0;

        for(int right = 0 ; right < sorted.size() ; right ++){
            if(sorted[right] != 0){
                for(int j = left ; j < right; j++){
                    sorted[j] = sorted[right];
                }
                left = right + 1;
            }
        }


        int bought = 0;

        for(int  n : sorted){
            if(coins >= n){
                coins -= n;
                bought++;
            }
        }

        return bought;
    }
};