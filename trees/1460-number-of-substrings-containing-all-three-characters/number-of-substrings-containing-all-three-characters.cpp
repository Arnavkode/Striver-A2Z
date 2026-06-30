class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(100, 0);
            int left = 0;

        int ans= 0;
        for(int right =0 ; right < s.size() ; right++){
            freq[s[right]]++;
            while(left < right && freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0){
                freq[s[left]]--;
                left++;

            }
            ans += left;
        }
        return ans;
    }
};