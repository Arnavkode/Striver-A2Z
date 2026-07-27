class Solution {
public:
    int perimeter = 0;
    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>> & vis){
            int nbrs = 0;

        for(auto v : dirs){
            int newx = x + v[0];
            int newy = y + v[1];
            if(newx >=0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && grid[newx][newy] == 1){
                
                nbrs++;
                if(vis[newx][newy] == 0){
                    vis[newx][newy] = 1;
                dfs(newx, newy, grid, vis);
                }
            }
            
        }
        perimeter += (4 - nbrs);
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),  vector<int>(grid[0].size() , 0));

        for(int i =0 ; i < grid.size() ; i++){
            for(int j =0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    vis[i][j] = 1;
                    dfs(i, j , grid, vis);
                }
            }
        }
        

        return perimeter;
    }
};