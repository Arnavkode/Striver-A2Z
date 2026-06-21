class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> eff(m , vector<int>( n, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, 0,0});
        eff[0][0] = 0;
        // effort, x, y

        vector<vector<int>> dirs = {{1,0}, { 0,1}, {-1,0},{0, -1}};
        while(!pq.empty()){
            auto p = pq.top();
            int effort = p[0];
            int x = p[1];
            int y = p[2];


            pq.pop();
            if(effort > eff[x][y]) continue;

            for(auto v : dirs){
                int newx = x + v[0];
                int newy = y + v[1];

                if(newx >= 0 && newx <m && newy >= 0 && newy < n){
                    int newefrt = max(effort , abs(heights[x][y] - heights[newx][newy]));
                    if(newefrt < eff[newx][newy]){
                        eff[newx][newy] = newefrt;
                        pq.push({newefrt, newx, newy});
                    }
                }
            }
        }

        return eff[m-1][n-1];
    }
};

// 