class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        //  reverse odd rows
        int m = matrix.size();
        int n = matrix[0].size();
        // boundaries
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = m -1;

        vector<int> res;

        while(left <= right && top <= bottom){

            // go right on top boundary
            for(int i = left; i <= right ;i++){
                res.push_back(matrix[top][i]);
            }
            top++;

            // go down on right boundary
            for(int i = top ; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;

            // go left on bottom boundary
            if(top<=bottom){for(int i = right; i>=left ; i--){
                res.push_back(matrix[bottom][i]);
            }
            bottom--;}

            // go up on left boundary
            if(left<=right){for(int i = bottom; i>=top; i--){
                res.push_back(matrix[i][left]);
            }
            left++;}
        }
        
        return res;
    }
};

// print the matrix in spiral order
// brute force would be if reached a wall/boundary turn 
// to do that ig if statement on whether iterator is at m/n
// fir next iteration mai m-1 and n-1 would be treated as boundaries?
// /but what would iterate the boundaries????

// bro i can just reverse the odd rows and traverse as is
// no but that would have made sense if i had to go in a zigzag pattern
// there must be a transformation for this

// per loop traversal? sort of recursive but were looping through levels of n

