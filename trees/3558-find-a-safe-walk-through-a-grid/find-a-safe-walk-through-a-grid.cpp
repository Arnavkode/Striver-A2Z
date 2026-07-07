class Solution {
public:

    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        // dijkstra with health
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int cost = grid[0][0];
        pq.push({cost, 0 ,0 });
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dis(m, vector<int> (n, INT_MAX));
        dis[0][0] = grid[0][0];

        while(!pq.empty()){
            auto v = pq.top();
            int dist = v[0];
            int x = v[1];
            int y = v[2];
            pq.pop();

            if(dist > dis[x][y]) continue;

            for(auto v : dirs){
                int newx = x + v[0];
                int newy = y + v[1];

                if(newx >= 0 && newx < m && newy >=  0 && newy < n){
                    int newdist = dist + grid[newx][newy];

                    if(newdist <  dis[newx][newy]){
                        dis[newx][newy] = newdist;
                        pq.push({newdist, newx, newy});
                    }
                }
            }
        }

        if(dis[m-1][n-1] < health) return true;
        else return false;

    }
};