class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = -1;

        queue<pair<int, int>> q;
        int rotten = 0;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    rotten++;
                }
            }
        }

        if(rotten == 0 && fresh == 0) return 0;

        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};


        while (!q.empty()) {
            ans++;
            int qsize = q.size();
            while (qsize--) {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for (auto v : dirs) {
                    int newx = x + v[0];
                    int newy = y + v[1];

                    if (newx >= 0 && newx < m && newy >= 0 && newy < n &&
                        grid[newx][newy] == 1) {
                            fresh--;
                        grid[newx][newy] = 2;
                        q.push({newx, newy});
                    }
                }
            }
        }

        if(fresh > 0) return -1;
        return ans;

    }
};