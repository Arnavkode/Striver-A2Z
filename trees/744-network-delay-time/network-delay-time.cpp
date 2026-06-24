class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n +1, INT_MAX); //indexing warning

        vector<vector<pair<int, int>>> adj(n +1);

        for(int i =0 ; i < times.size()  ; i ++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, k});
        dis[k] = 0;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int dist = p.first;

            if(dist > dis[node]) continue;

            for(auto p : adj[node]){
                int nbr = p.first;
                int wt = p.second;

                if(dist + wt < dis[nbr]){
                    dis[nbr] = dist + wt;
                    pq.push({dis[nbr], nbr});
                }
            }
        }

        int ans = INT_MIN;

        for(int i =1 ; i < n+1 ; i ++){
            if(dis[i] == INT_MAX ) return -1;
            ans = max(ans, dis[i]);
        }

        return ans;


    }
};