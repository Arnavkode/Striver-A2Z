class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> fre1(26, 0);
        int window = s1.size();

        for(char c : s1) fre1[(c - 'a')]++;

        for (int i = 0; i + window <= s2.size(); i++) {
        vector<int> fre2(26, 0);

            string temp = s2.substr(i, window);
            for(char c: temp) fre2[c - 'a']++;

            if (fre2 == fre1) return true;
        }

        return false;
    }
};