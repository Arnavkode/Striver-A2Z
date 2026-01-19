class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int sizes = s.size();
        int sizet = t.size();
        if(sizes != sizet) return false;
        for(int i =0 ; i< sizes; i++){
            if(s[i] != t[i]) return false;

        }

        return true;
        
    }
};