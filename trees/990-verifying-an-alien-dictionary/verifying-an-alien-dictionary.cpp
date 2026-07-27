class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int, int> wordOrder;
        int rank = 0;
        for(char c : order){
            rank++;
            wordOrder[c - 'a'] = rank;
        }

        for(int i = 0; i < words.size() -1; i++){
            
            for(int j = 0 ; j < words[i].size() ; j++){
                if(j == words[i+1].size()) return false;
                if(wordOrder[words[i][j] - 'a'] > wordOrder[words[i+1][j] - 'a']) return false;
                else if(wordOrder[words[i][j] - 'a'] < wordOrder[words[i+1][j] - 'a']) break;
                // similar string logic

            }
        }

        return true;
    }
};