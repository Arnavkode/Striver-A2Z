class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        // store every substring    
        set<string> subs;

        for(int i = 0 ; i < word.size() ; i++){
            string sub = "";
            for(int  j = i ; j < word.size() ; j++){
                sub += word[j];
                subs.insert(sub);
            }
        }
        int ans = 0;

        for(int i =0 ; i  <patterns.size() ; i++){
            if(subs.contains(patterns[i])) ans++;
        }

        return ans;
    }
};