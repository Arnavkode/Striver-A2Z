class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startcolor = image[sr][sc];

        queue<pair<int,int>> q;
        vector<vector<int>> vis(image.size() , vector<int> (image[0].size()));
        q.push({sr, sc});
        vector<vector<int>> dirs ={{0,1},{1,0},{-1,0},{0,-1}};
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            for(auto v : dirs){
                int newx = x + v[0];
                int newy = y + v[1];

                if(newx >= 0 && newx < image.size() && newy >= 0 && newy < image[0].size() && image[newx][newy] == startcolor && vis[newx][newy] == 0){
                    vis[newx][newy] = 1; 
                    image[newx][newy] = color;
                    q.push({newx, newy});
                }
            }
        }

        return image;
    }
};