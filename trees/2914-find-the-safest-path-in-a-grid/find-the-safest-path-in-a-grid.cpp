class Solution {
public:
    bool pathExists(vector<vector<int>>& grid, vector<vector<int>>& dis, int safeness){
        queue<pair<int,int>> q;
        int n = grid.size();
        if(dis[0][0] < safeness) return false;
        q.push({0,0});
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int x = p.first;
            int y=  p.second;

            if(x == grid.size() -1 && y == grid.size() -1) return true;

            if(x + 1 < n && grid[x+1][y] != 1 && !vis[x+1][y] && dis[x + 1][y] >= safeness){
                q.push({x+1, y});
                vis[x+1][y] = 1;
            }
            if(y + 1 < n && grid[x][y +1] != 1 && !vis[x][y+1] && dis[x][y+1] >= safeness){
                q.push({x, y+1});
                vis[x][y+1] = 1;
            }
            if(x - 1 >= 0  && grid[x-1][y] != 1 && !vis[x-1][y] && dis[x-1][y] >= safeness){
                q.push({x-1, y});
                vis[x-1][y] = 1;
            }
             if(y - 1 >= 0  && grid[x][y-1] != 1 && !vis[x][y-1] && dis[x][y-1] >= safeness){
                q.push({x, y-1});
                vis[x][y-1] = 1;

            }
            
            
        }

        return false;

    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

        vector<pair<int,int>> theifs;
        for(int i =0; i < n; i++){
            for(int j = 0 ; j < n; j++){
                if(grid[i][j] == 1) theifs.push_back({i,j});
            }
        }

        vector<vector<int>> dis(n, vector<int>(n,0));

        vector<vector<int>> vis(n , vector<int>(n , 0));
        queue<pair<int,int>> q;
        for(auto p : theifs){
            q.push(p);
            vis[p.first][p.second] = 1;
        }

        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto v : dirs){
                int newx = x  + v[0];
                int newy = y  + v[1];

                if(newx >= 0 && newx <n && newy >= 0 && newy <n && vis[newx][newy] == 0){
                    dis[newx][newy] = dis[x][y] + 1;
                    vis[newx][newy] = 1;
                    q.push({newx,newy});
                }
            }

        }

        // binary search from 0 to maximum safeness factor could be
        int left = 1;
        int right = n*n;

        while(left < right){
            int mid = (left + right)/2;
           
            if(pathExists(grid, dis, mid )) left = mid +1;
            else right = mid;
        }
        return left-1;
        
    }
};

// given a 0 indexed 2d matri
// 1 -> thief
// 0 -> empty
// minimum mnahattan distance ofany cell int he path tot any theif in the grid
// dijkstra 

// calculate manhattan then 
