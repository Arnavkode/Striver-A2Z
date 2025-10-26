class Solution {
public:
    int myAtoi(string s) {
        bool negative = false;
        bool leading = false;
        int digit = 10;
        long long mynum = 0;
        int  n = s.size();
        int i = 0;
        while(i < n && s[i] ==  ' ' ) i++;
        if(s[i] == '-' || s[i] == '+'){ s[i] == '-'? negative = true: negative = false; i++;}

        while(i<n && isdigit(s[i])){
            mynum = mynum*10 + (int)s[i] - 48;
            i++;
            if(!negative && mynum > INT_MAX) return INT_MAX;
            if(negative && mynum > INT_MAX) return INT_MIN;
        }
        if(negative) mynum *= -1;
        

        return mynum;
    }
};

// what i dont get is how you treat some 0 as leading with other as a digit in 0-1
// 