class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector<pair<int,int>> zeroes;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0;i < m; i++){
            for(int j = 0 ; j<n ; j++){
                if(matrix[i][j] == 0) zeroes.push_back({i,j});
            }
        }

        for(auto p: zeroes){
            for(int i = 0; i<n; i++){
                matrix[p.first][i] =0;
            }
            for(int i = 0; i<m ; i++){
                matrix[i][p.second] = 0; 
           }
        }

        
    }
};

// if found 0 in matrix, poore column and row ko make 0
// BRUTE:
// if i,j keep i ko contant run poora j making 0 then keep j ko constant run poora i ko 0
// could replace that vector with a balkc vector, would take space complexity more
// need to find the positions of 0 first then operate usme O(N2)

// but what if the matrix is empty? empty matrix m = 0, n=0 loops wont run
// only row m = 1, n=x then would work as loop would run only one time. similarly fo rcolumn asw