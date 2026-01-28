class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            // FAILURE CASE:
            // If the current index 'i' is beyond our maximum reach,
            // it means we are stuck and cannot step here.
            if(i > maxReach) return false;
            
            // GREEDY UPDATE:
            // Can we extend our reach from this position?
            // maxReach = max(current best, current index + jump power)
            maxReach = max(maxReach, i + nums[i]);
            
            // Optimization: If we can already reach the end, stop early.
            if(maxReach >= n - 1) return true;
        }
        
        return true;
    }
};