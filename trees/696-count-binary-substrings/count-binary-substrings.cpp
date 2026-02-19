class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans =0;
        if(s.size() == 0) return 0;
        vector<int> groups;
        char last = s[0];
        int cons = 0;
        for(int i = 0; i< s.size() ; i++){
            if(s[i] == last) cons++;
            else{
                groups.push_back(cons);
                cons = 1;
            }
            last = s[i];
        }
        groups.push_back(cons);
        for(int i = 0 ;i < (int)groups.size()-1; i++){
            ans += min(groups[i] , groups[i+1]);
        }
        return ans ;
    }
};
// nigga what
// bianry substrings where there are equal number of consecutivelty placed 0s and 1s