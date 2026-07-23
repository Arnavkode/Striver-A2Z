class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        sort(s1.begin(),s1.end());
        int window = s1.size();

        for (int i = 0; i + window <= s2.size(); i++) {
            string temp = s2.substr(i, window);
            sort(temp.begin(), temp.end());

            if (temp == s1) return true;
        }

        return false;
    }
};