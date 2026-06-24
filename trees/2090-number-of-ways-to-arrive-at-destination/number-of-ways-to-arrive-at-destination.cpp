class Solution {
public:
using ll = long long;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<ll> dis(n, LLONG_MAX);
        vector<vector<pair<ll,ll>>> adj(n);

        vector<vector<int>> wts(n, vector<int> (n));

        for(int i =0 ;i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
            wts[roads[i][0]][roads[i][1]] = roads[i][2];
            wts[roads[i][1]][roads[i][0]] = roads[i][2];
        }


        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

        pq.push({0, 0});

        dis[0] = 0;
        int ans = 0;
        while(!pq.empty()){
            auto p = pq.top();
            ll dist = p.first;
            ll node = p.second;

            pq.pop();

            if(dist > dis[node]) continue;


            for(auto v : adj[node]){
                ll nbr = v.first;
                ll wt = v.second;

                if(dist+ wt <dis[nbr]){

                    dis[nbr] = dist + wt;
                    pq.push({dis[nbr], nbr});
                }
            }
        }

        long long MOD = 1e9 + 7;


        // okay so ill let dp take over

        // dp[i] -> number of shortest path from 0 to i

        vector<ll> dp(n, 0);
        dp[0] = 1;
        vector<pair<ll,ll>> ord;

        for(int i =0 ; i < n; i++){
            ord.push_back({ dis[i], i});
        }

        sort(ord.begin(), ord.end());
        
        for(int i = 0; i < n ; i++){
            ll node =ord[i].second;
            ll mindis = ord[i].first;

            for(auto x : adj[node]){
                ll wt = x.second;
                ll nbr = x.first;

                if(dis[node] + wt == dis[nbr]){ dp[nbr] = (dp[nbr] + dp[node])%MOD;
                
                }
            }
        }
        return dp[n-1]% MOD;
    }
};

// city with intersections
// bi - directional = undirected
// number of ways?
// seems DFS?
// variation of dijkstra
// number of