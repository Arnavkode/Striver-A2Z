class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // map strings to their sort

        unordered_map<string, vector<string>> srt;
        for(string s: strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            srt[sorted].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto p : srt){
            vector<string> loc;
            for(string s: p.second){
                loc.push_back(s);
            }
            ans.push_back(loc);
        }

        return ans;
    }
};

