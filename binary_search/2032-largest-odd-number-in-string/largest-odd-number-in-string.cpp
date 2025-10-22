class Solution {
public:
    string largestOddNumber(string num) {
        int maxi = 0;
        int n = num.size();
        string ans;
        bool found = false;
        for(int i = n-1; i>=0;i--){
            if(found){ ans.append(1, num[i] );continue;}
            int temp = num[i];
            if(temp%2 == 1){
                found  = true;
                ans.append(1, num[i] );
            }
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

// find out the larget odd number