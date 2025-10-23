class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> check1;
        unordered_map<char, char> check2;
        int n = s.size();
        // mapping s to t
        for(int i = 0; i<n ; i++){

            if(check1.count(s[i]) == 0 && check2.count(t[i]) == 0){
                check1[s[i]] = t[i];
                check2[t[i]] = s[i];
            }
            else{
                if(check1[s[i]] != t[i] || check2[t[i]] != s[i]){
                    return false;
                }
            }
        }

        return true;

        
    }
};
// basically saying that once a letter maps to anothr it cant be changes
// might use a map<char,char> for mapping
// ill have to check both ways ig, is there any way to make one primary?

