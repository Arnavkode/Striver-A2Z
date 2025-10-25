class Solution {
public:
    int maxDepth(string s) {

        int maxi = 0;
        int count = 0;
        for(char c: s){

            if(c == '('){count++;
            maxi = max(count, maxi);}
            if(c == ')'){ 
                count--;
                 } 

        }
        return maxi;
        
    }
};

// given a string
// what i need to do is just check for unaccounted/not closed parentheses (
// maintain a max counter 