class Solution {
public:
    pair<int, int> findPar(pair<int, int> u,
                           vector<vector<pair<int, int>>>& parent) {
        int x = u.first;
        int y = u.second;

        if (parent[x][y].first == x && parent[x][y].second == y)
            return {x, y};
        return parent[x][y] =
                   findPar({parent[x][y].first, parent[x][y].second}, parent);
    }

    void joinBySize(pair<int, int> u, pair<int, int> v,
                    vector<vector<pair<int, int>>>& parent,
                    vector<vector<int>>& size) {
        auto par1 = findPar(u, parent);
        auto par2 = findPar(v, parent);
        if(par1 == par2) return;

        if (size[par1.first][par1.second] > size[par2.first][par2.second]) {
            parent[par2.first][par2.second] = {par1.first, par1.second};
            size[par1.first][par1.second] += size[par2.first][par2.second];

        } else if (size[par1.first][par1.second] <
                   size[par2.first][par2.second]) {
            parent[par1.first][par1.second] = {par2.first, par2.second};
            size[par2.first][par2.second] += size[par1.first][par1.second];

        } else {
            parent[par1.first][par1.second] = {par2.first, par2.second};
            size[par2.first][par2.second] += size[par1.first][par1.second];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int, int>>> parent(m, vector<pair<int,int>>(n, {-1, -1}));


        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j] == 1){
                    parent[i][j] = {i,j};
                }
            }
        }
        vector<vector<int>> size(m, vector<int>(n,1));
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        bool seenzero= false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (auto v : dirs) {
                        int newx = i + v[0];
                        int newy = j + v[1];

                        if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
                            if (grid[newx][newy] == 1) {
                                joinBySize({i, j}, {newx, newy}, parent, size);
                            }
                        }
                    }
                }
                else seenzero = true;
            }
        }
        int ans = -1;
        
        for(int i = 0 ; i<m; i++){
            for(int j = 0; j < n ; j++){
        set<pair<int,int>> seen;

                int rootsize = 0;
                if(grid[i][j] == 0){
                    for (auto v : dirs) {
                        int newx = i + v[0];
                        int newy = j + v[1];

                        if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
                            if(grid[newx][newy] == 1){
                                auto root = findPar({newx, newy}, parent);
                                if(!seen.contains(root)){rootsize += size[root.first][root.second];
                                seen.insert(root);}
                                

                            }
                        }
                    }

                    ans = max(ans, rootsize +1);

                }
            }
        }

        return seenzero? ans : m*n;
    }
};
// could do by disjoint sets either or by
// have a rank vector