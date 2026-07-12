class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        map<int, vector<int>> ranks;

        for(int i = 0; i < arr.size() ; i++){
            ranks[arr[i]].push_back(i);
        }
        
        vector<int> ans(arr.size());
        int rank = 0;

        for(auto p : ranks){
            rank++;
            for(int idx : p.second){
                ans[idx] = rank;
            }
        }
        return ans;


        
    }
};