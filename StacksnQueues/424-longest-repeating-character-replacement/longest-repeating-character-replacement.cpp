class Solution {
public:
    int characterReplacement(string s, int k) {

            int left = 0;
            int ans = 0;
            int maxfreq = 0;
            unordered_map<char,int> freq;
            // ill have to take care of  different character asw, majority in current substr is the best one
            for(int right = 0; right < s.size() ; right++){
                freq[s[right]]++;
                maxfreq = max(maxfreq , freq[s[right]]);
                while(((right - left + 1) -maxfreq) > k ){
                    freq[s[left]]--;
                    left++;
                }

                ans = max(ans, right-left +1);
            }

            return ans;

        
    }
};


// its like 0s and 1s problem
// as long as the current number of diff chars less than the current one, i can go and include it in the answer

// hmmm a formula that gemini told me is 
// no of replacements needed = letter count - most frequent character

