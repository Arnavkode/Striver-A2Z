class Solution {
public:

    bool pathExists(vector<vector<int>>& grid, int t){

        if(grid[0][0] > t) return false;
                int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n , 0));

        stack<pair<int,int>> stk;

        stk.push({0,0});
        
        vis[0][0] =1;

        while(!stk.empty()){
            auto p  =stk.top();
            stk.pop();
            int x = p.first;
            int y = p.second;

            if(x == m-1 && y == n-1) return true;

            for(auto v : dirs){
                int newx = x + v[0];
                int newy = y + v[1];

                if(newx >=0  && newx < m && newy >= 0 && newy < n && vis[newx][newy] == 0 && grid[newx][newy] <= t){
                    vis[newx][newy] = 1;
                    stk.push({newx,newy});
                }
            }
            
        }

        return false;
 }
    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        // DFS + Binary search

        int high = -1;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n ; j++){
                high = max(high, grid[i][j]);
            }
        }

        int low = 0;

        while(low < high){
            int mid = (low + high)/2;
            if(pathExists(grid, mid)) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};