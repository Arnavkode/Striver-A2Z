class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<vector<int>> bskts;

        for(int i =0 ; i < baskets.size(); i++){
            bskts.push_back({baskets[i], 0});
        }

        int notplaced = fruits.size();

        for(int i = 0; i < fruits.size(); i++){
            for(int j = 0; j <bskts.size(); j++){
                if(bskts[j][0] >= fruits[i] && bskts[j][1] == 0){
                    bskts[j][1] = 1;
                    notplaced--;
                    break;
                }
            }
        }

        return notplaced;
    }
};