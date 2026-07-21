class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        vector<int> zeroes;
        int curr = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                curr++;
            if (s[i] == '1') {
                if (curr > 0) {
                    zeroes.push_back(curr);
                    curr = 0;
                }
            }
        }
    

    if (curr > 0)
        zeroes.push_back(curr);
    int ones = 0;

    for (char c : s) {
        if (c == '1')
            ones++;
    }
    int maxdel = 0;
    for (int i = 1; i < zeroes.size() ; i++) {
        maxdel = max(maxdel, zeroes[i] + zeroes[i - 1]);
    }

    return ones + maxdel;
}
}
;