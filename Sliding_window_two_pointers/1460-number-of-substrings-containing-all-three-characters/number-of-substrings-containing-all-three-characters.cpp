class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> freq; //store freq against char

        int left = 0;
        int ans = 0;
        int curr;

        for(int right = 0; right < s.size() ; right++){
            freq[s[right]]++;

            while(left < right && freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0){
                freq[s[left]]--;
                left++;
            }//do this to find the smallest substring containing all three of the chars

            ans += left; //i can just add elft cuz if the current window has all the characters, the windows previous to that must have them too

        }
        return ans;
        
    }
};

// number of substrings containing all three chars at least once
// i cud have a frequecy check
// or i could have the all - none
// subtract the respeated ones
// repetition can be tracked thru a map


// ok yest i saw the solution, but it aligned with basically keeping a track of all the frequecies
// since we know all three numbers