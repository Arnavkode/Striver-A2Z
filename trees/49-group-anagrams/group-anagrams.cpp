class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> idx;

        for(int i = 0 ; i < strs.size() ; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            idx[temp].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto p : idx){
            ans.push_back(p.second);
        }

        return ans;
    }
};