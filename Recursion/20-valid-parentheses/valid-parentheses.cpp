class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brackets;
    brackets['['] = ']';
    brackets['{'] = '}';
    brackets['('] = ')';
        stack<char> stn; //situation rn
        for(char c: s){
            if(brackets.count(c)) stn.push(c);

            else if(!stn.empty() && brackets[stn.top()] == c){
                stn.pop();
            }
            else return false;
        }

        if(stn.empty()) return true;
        else return false;
        
    }
};