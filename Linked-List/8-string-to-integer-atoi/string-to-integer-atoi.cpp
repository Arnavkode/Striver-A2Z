class Solution {
public:

    int recur(int i, string& s, long long& num, bool negative){
        
        if(!isdigit(s[i]) || i == s.size()) return num;
        
        

        num = num * 10 +(int)(s[i] - '0');
         if(!negative && num > INT_MAX) return INT_MAX;
         else if(num > (long long)(INT_MAX) + 1) return INT_MIN;
        num = recur(++i, s, num, negative);


        return num;
        
    }
    int myAtoi(string s) {
        long long num = 0;
        int i =0;
        bool negative = false;
        while( s[i] == ' ' && i < s.size()) i++;
        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '-') negative = true;
            i++;
        }
        int ans = recur(i, s, num, negative); 

        if(!negative && ans == INT_MAX) return INT_MAX;
        if(ans == INT_MIN) return INT_MIN;

        if(negative) return -1*ans;
        else return ans;       
    }
};

// what i dont get is how you treat some 0 as leading with other as a digit in 0-1
// STRING SOLUTION

// bool negative = false;
//         bool leading = false;
//         int digit = 10;
//         long long mynum = 0;
//         int  n = s.size();
//         int i = 0;
//         while(i < n && s[i] ==  ' ' ) i++;
//         if(s[i] == '-' || s[i] == '+'){ s[i] == '-'? negative = true: negative = false; i++;}

//         while(i<n && isdigit(s[i])){
//             mynum = mynum*10 + (int)s[i] - 48;
//             i++;
//             if(!negative && mynum > INT_MAX) return INT_MAX;
//             if(negative && mynum > INT_MAX) return INT_MIN;
//         }
//         if(negative) mynum *= -1;
        

//         return mynum;



// Recursive solution
// converts at 32-bit signed interger , although prone to overflow
// ignore whitespace
// determine the sign
// read the integers and skip leading 0s

// if i make a recursive function, a normal one, all i can do to control hes tuff is 
// is place return statements appropriately