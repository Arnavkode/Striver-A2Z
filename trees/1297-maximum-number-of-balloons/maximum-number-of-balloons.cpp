class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> freq;

        string txt = "balloon";

        for(char c: txt) freq[c] = 0;

        for(char c : text){
            if(freq.count(c)){
                freq[c]++;
            }
        }

        freq['l'] =  floor(freq['l']/ 2.0);
                freq['o'] =  floor(freq['o']/ 2.0);
        int ans = INT_MAX;
        for(auto p : freq){
            ans = min(ans, p.second);
        }
        


        return ans;
        
    }
};

// 