class Solution {
public:

    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: **Transpose** the matrix
        // Swap elements across the main diagonal
       for(int i = 0; i<n ; i++){
        for(int j =0; j<i; j++){
            int temp = matrix[j][i] ;
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        } 
       }

       for(int i = 0; i<n ; i++){
        int high = n-1;
        int low = 0;
        while(low < high){
            int temp = matrix[i][low];
            matrix[i][low] = matrix[i][high];
            matrix[i][high] = temp;
            high--;
            low++;
        }
       }
    }

};

// given matrix, rotate 90 degrees
// matrix would be square only
// i can sense that we could start from the middle (n=1) and source outward each step to rotate?
// need to figure out the rotating mechanism kind of
// have another matrix and allocate it there? but idk the rule to do it?


// 1,1 goes to 1,3
// 1,2 goes to 2,3
// 1,3 gows to 3,3

// 3,1 to 1,1
// 2,1 to 1,2

// corner elements just shit to the next
// 1,2 to 2,4
// 1,3 to 3,4
// 1 to 4
// the column turns into row?
// 2,4 to 4,3
// YES
// the newrow = oldcol
// newcol = n- oldrow +1

// LYASGO

// it was literally transpose and reverse each array