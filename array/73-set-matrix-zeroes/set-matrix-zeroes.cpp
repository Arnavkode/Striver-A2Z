class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        bool flagifzeroexistsinrow = false;
        bool flagifzeroexistsincol = false;

        for(int i =0 ; i<m; i++){
            if(matrix[i][0] == 0){
                flagifzeroexistsinrow = true;
            }
        }

        for(int i =0 ; i<n; i++){
            if(matrix[0][i] == 0){
                flagifzeroexistsincol = true;
            }
        }

        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n ;j ++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(flagifzeroexistsinrow){
            for(int i = 0;i<m;i++){
                matrix[i][0] = 0;
            }
        }

        if(flagifzeroexistsincol){
            for(int i = 0;i<n;i++){
                matrix[0][i] = 0;
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


// TC : O(M*N)
// SC : O(M*N) as the worst case every element is 0 and getts stored in the vector


// Instead of storing vectors i could just note which row and whihc column have zeroes
//  that would lessen it down to O(m+n)


// if i,j found 0 make the first row/column = 0, then scan it again andif 0 found in a row/column 
// in the first iteration then zero the entire row/column
// since if the zero pehle se tha then that first row and column ko bhi zero karna padega
// so we use a flag is there eexisted a zero ina  row or column before and if yes we xero the entire row and column
