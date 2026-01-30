class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 1) return 1;

        // okay i kinda get ratings but be greedy
        // neighbors (positions) matter
        vector<int> candies(ratings.size(), 1);
        // i give 1 candy to the first
        // forward pass
        for(int i =1; i< ratings.size() ; i++){
            if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1] +1;
        }

        // backward pass
        for(int i = ratings.size() -2; i >=0; i--){
            if(ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1] + 1);
        }

        int tot = 0;
        for(int c : candies) tot+=c;
        return tot;
    }
};
// n small ngas standing in a lnine
// each child has rating
// each child must have at least oone candy
// children with higher rating must get more candies than their neighborss
// thishas to have a simple ass logi
// uhm if mere saamen wal is higher than me, then i add candies++;
// if its the same or lower then ill go candies--;

// im kind of in the right direction, so theres two passes