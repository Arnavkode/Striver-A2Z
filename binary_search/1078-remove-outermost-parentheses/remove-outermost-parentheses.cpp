class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        bool inside = false;
        int n = s.size();
        int bracket = -1;
        
        for( char c: s){
            if(c == ')') bracket--;
            if(bracket >= 0) ans.append(1,c);
            if(c == '(') bracket++;
            
        }

        return ans;
    }
};