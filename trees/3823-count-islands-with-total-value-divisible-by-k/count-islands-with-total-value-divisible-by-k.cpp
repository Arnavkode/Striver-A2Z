class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int value(int rx, int ry, vector<vector<int>>& grid,vector<vector<int>>& vis, int k ){
        queue<pair<int,int>> q;
        long long value = 0;
        q.push({rx,ry});
        vis[rx][ry] = 1;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            value += grid[x][y]%k;
            q.pop();


            for(auto dir : dirs){
                int newx = x + dir[0];
                int newy = y + dir[1];

                if(newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] > 0 && vis[newx][newy] == 0){
                    q.push({newx, newy});
                    vis[newx][newy] = 1;
                    
                }
            }
        }

        return value;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int ans =0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j] > 0 && vis[i][j] == 0 && (value(i, j, grid,vis, k)%k == 0))ans++;
            }
        }
        return ans;
    }
};