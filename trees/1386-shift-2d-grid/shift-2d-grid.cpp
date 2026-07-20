class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        vector<int> vec;
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ;j++){
                vec.push_back(grid[i][j]);
            }
        }
        int size =  vec.size();
        k = k%size;

        for(int i = 0; i < m; i++){
            for(int j = 0 ; j  < n; j++){
                grid[i][j] = vec[((i*n + j + (m*n - k)))%size];
            }
        }
        return grid;
    }   
};

// ah okay one shift ahead
