class Solution {
public:
    
int carFleet(int target, vector<int>& position, vector<int>& speed) {

        if(speed.size() == 1) return 1;
        if(speed.size() == 0) return 0;

           
        vector<pair<int,int>> pairs;
        for(int i = 0 ;i < speed.size() ; i++){

        pairs.push_back({position[i], speed[i]});
        }

        sort(pairs.rbegin(), pairs.rend());



        double prevtime = 1.0*(target - pairs[0].first)/ pairs[0].second; //TIME TO REACH THE TARGET OF THE CLOSEST CAR

       

        int fleet = 1;
        for(int  i = 1; i<position.size() ; i++){


        
        double currtime =  1.0*(target - pairs[i].first)/ pairs[i].second;

        if(currtime > prevtime){ ++fleet;
                prevtime = currtime;}

        }

        return fleet;

        }

};