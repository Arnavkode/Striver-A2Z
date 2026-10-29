class Solution {
public:


    int m, n;
    int ans = INT_MAX;
    void minXOR(int x, int y, int curr, vector<vector<vector<bool>>>& dp, vector<vector<int>>& grid){
        
       if(dp[x][y][curr] == true) return;
       dp[x][y][curr] = true;
        if(x+1 < m){
            
            minXOR(x+1, y, curr ^ grid[x+1][y], dp, grid);
        }
        if(y+1 < n){
            
            minXOR(x, y+1, curr ^ grid[x][y+1], dp, grid);
        }
        return;        
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024)));
        // dp[i][j][xor] tells if i,j is reachable from 0,0 and has the XOR value v
        minXOR(0, 0, grid[0][0],dp, grid);

        for(int i = 0 ; i < 1024 ; i++){
            if(dp[m-1][n-1][i] == true){ans = min(ans, i);};
        }
        return ans;
    }
};

// plan is to cut recursion if the XOR 