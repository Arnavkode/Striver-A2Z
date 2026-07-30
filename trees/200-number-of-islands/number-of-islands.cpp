class Solution {

public:

    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    void dfs(int srx , int sry , vector<vector<char>>& grid, vector<vector<int>> &vis){

        stack<pair<int,int>> stk;
        stk.push({srx,sry});
        vis[srx][sry] = 1;
        while(!stk.empty()){
            int x = stk.top().first;
            int y = stk.top().second;
            stk.pop();
            for(auto v : dirs){
                int newx = x + v[0];
                int newy = y + v[1];

                if(newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && grid[newx][newy] == '1' && vis[newx][newy] == 0){
                    vis[newx][newy] = 1;

                    stk.push({newx, newy});
                }
            }
             
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
 vector<vector<int>> vis(m,  vector<int> (n));
    int count  =0 ;

        for(int i =0 ; i < grid.size() ; i++){
            for(int j =0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    count++;

                    dfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};