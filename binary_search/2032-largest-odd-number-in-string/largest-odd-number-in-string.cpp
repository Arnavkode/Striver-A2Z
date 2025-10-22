class Solution {
public:
    string largestOddNumber(string num) {
        int end = -1;
        int n = num.size();
        
        for(int i = n-1; i >= 0 ; i--){
            if((int)num[i]%2 == 1){
                end = i;
                break;
            }
        }
        if(end == -1 ) return "";
        else return num.substr(0,end +1);
    }
};

// find out the larget odd number