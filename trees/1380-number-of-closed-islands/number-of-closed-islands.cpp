class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void bfs(int x, int y, vector<vector<int>>& grid) {

        if(grid[x][y] == 1) return;
        queue<pair<int, int>> q;

        q.push({x, y});
        grid[x][y] = 1;

        while (!q.empty()) {
            int xnbr = q.front().first;
            int ynbr = q.front().second;
            q.pop();

            for (auto dir : dirs) {
                int newx = xnbr + dir.first;
                int newy = ynbr + dir.second;

                if (newx >=0 && newy >=0 && newx < grid.size() && newy < grid[0].size() && grid[newx][newy] == 0) {
                    q.push({newx, newy});
                    grid[newx][newy] = 1;
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            if(grid[i][0] == 0) bfs(i, 0, grid);
            if(grid[i][n-1] == 0) bfs(i, n-1, grid);
        }

        for (int j = 0; j < n; j++) {

                if(grid[0][j] == 0) bfs(0, j, grid); 
                if(grid[m-1][j] == 0) bfs(m-1, j, grid); 
            }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 0){
                    ans++;
                    bfs(i, j , grid);
                }
            }
        }

        return ans;
    }
};