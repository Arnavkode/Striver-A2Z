class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // i just need to find the smallest difference between any of the two scores
        if(k == 1) return 0;
        if(nums.size() < k) return 0;

        sort(nums.begin() , nums.end());
        //since sorted i just need to go subsequent but the complexity is now nlogn
        int ans = INT_MAX;

        for(int i = 0; i<= nums.size() - k; i++){
            ans = min ( ans , nums[i+k-1] - nums[i]);
            // gettimng the max and min on each window
        }
        return ans;

        
    }
};

// okay given easy hai
// o - indexed interger array 
// ith score is ith student
// given interger k
// need to find the score of k students such that the iff between highest and the lowes scores is minimized