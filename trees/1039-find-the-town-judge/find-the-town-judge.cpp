class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> trusts(n+1);
        vector<vector<int>> trustedBy(n+1);

        for(auto x : trust){
            int u = x[0];
            int v = x[1];

            trusts[u].push_back(v);
            trustedBy[v].push_back(u);
        }


        for(int i = 1; i < n+1; i++){
            if(trusts[i].size() == 0 && trustedBy[i].size() == n-1) return i;
        }
        return -1;
    }
};