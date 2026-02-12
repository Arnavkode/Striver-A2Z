class Solution {
public:
    int longestBalanced(string s) {

        int left = 0;
        int maxlen = 0;
        // i cannot put in sliding window cuz of no monotonocity
        // criteria for a balanced substring is that its length = number of
        // distinct * maxfreq
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> freq; // char vs frequency
        int maxfreq = 1;


            for (int j = i; j < s.size(); j++) {
                freq[s[j]]++;
                maxfreq = max(maxfreq, freq[s[j]]);

                if (j - i + 1 == freq.size() * maxfreq) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }

        return maxlen;
    }
};