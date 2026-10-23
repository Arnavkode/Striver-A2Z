class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        
        int ans = -1;

        for(int i =0 ; i < nums.size(); i++){
            if(nums[i] != i)ans = max(ans & nums[i], 0);
        }

        return max(ans, 0);
        // for swaps to work, the k must  have every bit set for both the misplaced numbers 
    }
};

// nums is a permutation of numbers from 0 to n01
// swao inly if nums[i] & nums[j] == k?
// max value fo k ti make the whole permutation non decreasing