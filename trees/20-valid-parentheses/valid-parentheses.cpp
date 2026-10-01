class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> close;
        close['('] = ')';
        close['['] = ']';
        close['{'] = '}';
        for(char c: s){
        

            if(!stk.empty() && c == close[stk.top()]){
                stk.pop();
            }else{
                stk.push(c);
            }
        }

        return stk.empty();
    }
};