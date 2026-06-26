class Solution {
public:
    void dfs(int S, vector<vector<int>> & adj, vector<int>& vis){
        if(vis[S] == 1)return ;
        vis[S] = 1;
        for(int n :adj[S]) dfs(n, adj,vis);
        return;
    }
    // could be 
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(int i = 0 ; i < connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int> vis(n , 0);
        int ans = -1;


        for(int i = 0 ; i <n; i++){
            if(vis[i] == 0){
                ans++;
                dfs(i, adj, vis);
            }
        }

        
        if(connections.size() < (n-1)) return -1;


        return ans;
    }
};

// isnt the answer number of not connected computers?
// disconnected componenets