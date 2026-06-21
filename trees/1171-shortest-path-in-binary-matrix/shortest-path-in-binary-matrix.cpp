class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int s = grid.size();
        if(grid[0][0] == 1 || grid[s-1][s-1] == 1) return -1;
       vector<vector<int>> dirs = {{0,1}, {1,0}, {1,1}, { -1 ,1}, {1, -1}, { -1 , -1}, {0,-1}, { -1, 0}};


    //    top corner to lower bottom corner
         

         vector<vector<int>> dis(grid.size() , vector<int> (grid.size() , INT_MAX));
         dis[0][0] = 1;

         priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;

         pq.push({1, 0,0});
        bool possible = false;

         while(!pq.empty()){
            auto v = pq.top();
            int dist = v[0];

            int x = v[1];
            int y = v[2];
                        if(x == s -1 && y == s-1) possible = true;


            pq.pop();
            if(dist > dis[x][y]) continue;

            for(auto v : dirs){
                int newx = x + v[0];
                int newy = y + v[1];

                if(newx >= 0 && newx <grid.size() && newy >= 0 && newy < grid.size() && grid[newx][newy] == 0){
                    if(dist  + 1 < dis[newx][newy]){
                        dis[newx][newy] = dist + 1;
                        pq.push({dis[newx][newy], newx, newy});

                    }
                }
            }
         }

         return (possible ?  dis[s-1][s-1] :  -1);
    }
};