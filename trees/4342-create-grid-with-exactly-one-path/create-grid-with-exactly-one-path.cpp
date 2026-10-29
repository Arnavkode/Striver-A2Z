class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        int i = 0;
        int j = 0;

        while(i < m && j < n){
            grid[i][j] = '.';
            i++;
            if(i < m)grid[i][j] = '.';
            j++;
        }
        while(i < m){
            grid[i][j-1] = '.';
            i++;
        }
        while( j < n){
            grid[i-1][j] = '.';
            j++;
        }

        return grid;

    }
};