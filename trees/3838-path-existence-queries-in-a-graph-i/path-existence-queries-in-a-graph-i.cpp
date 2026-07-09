class Solution {
public:
    int findPar(int u, vector<int> & parent){
        if(parent[u] == u) return u;
        return parent[u] = findPar(parent[u], parent);
    }

    void join(int u , int v, vector<int> & parent){
        int paru = findPar(u, parent);
        int parv = findPar(v, parent);

        parent[paru] = parv;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        int last = 0;
        vector<int> parent(n);
        for(int i =0 ; i < n ; i++){
            parent[i] = i;
        }
        for(int i =0 ; i < nums.size() -1 ; i++){
            if(abs(nums[i] - nums[i+1]) <= maxDiff){
                join(i , i + 1, parent);
            } 
        }
        vector<bool> ans;

        for(auto q : queries){
            int u = q[0];
            int v = q[1];
            if(findPar(u, parent) == findPar(v,parent)) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
        
        
    }
};
// nums lenght doesnt allow nested loops