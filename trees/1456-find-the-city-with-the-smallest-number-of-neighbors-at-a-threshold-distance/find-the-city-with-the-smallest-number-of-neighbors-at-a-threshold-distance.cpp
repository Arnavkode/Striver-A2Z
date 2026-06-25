class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresh) {
        
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < edges.size() ; i++){
            dis[edges[i][0]][edges[i][1]] = edges[i][2];
            dis[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for(int i = 0; i < n ; i++){
            dis[i][i] = 0;
        }

        for(int k = 0 ; k < n; k++){
            for(int i = 0 ; i <n ; i ++ ){
                if(dis[i][k] != INT_MAX){ //NO EDGE

                    for(int j = 0 ; j <n; j++){
                        if(dis[k][j] != INT_MAX ){
                            // edge between k and j exists
                            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                        }
                    }
                
                }
            }   
        }
        int ans;
        int minCount = 1e8;
        for(int i =0 ; i < n ; i ++){
            int count = 0;
            
            for(int j = 0 ; j < n ; j ++){
                if(dis[i][j] <= thresh) count++;
            }
            if(count <= minCount){
                minCount = count;
                ans = i;
            }
        }
        return ans;
    }
};