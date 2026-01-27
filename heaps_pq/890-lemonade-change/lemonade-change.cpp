class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        unordered_map<int, int> map;
        map[5] = 0;
        map[10] = 0;
        map[20] = 0;

        for(int n : bills){
            if(n == 5){
                map[5]++;
            }
            if(n == 10){
                if(map[5] > 0){
                    map[5]--;
                    map[10]++;
                }else{
                    return false;
                }
            }

            if(n == 20){
                if(map[10] > 0 && map[5] > 0){
                    map[10]--;
                    map[20]++;
                    map[5]--;
                    continue;
                }
                else if(map[5] > 2){
                    map[5]--;
                    map[5]--;
                    map[5]--;
                    map[20]++;
                }
                else return false;
            }
        }

        return true;
        
    }
};
// lemonade cost  - 5 dolla
// currency - 5, 10, 20
// okay so need to just make a cashier sim