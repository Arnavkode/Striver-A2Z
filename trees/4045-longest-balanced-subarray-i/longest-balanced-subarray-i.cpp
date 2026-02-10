class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxLen = 0;
        int n = nums.size();

        // 1. Iterate over every possible starting point
        for (int i = 0; i < n; i++) {
            
            // 2. Reset sets for this new window
            unordered_set<int> distinctEvens;
            unordered_set<int> distinctOdds;
            
            // 3. Expand the window to the right
            for (int j = i; j < n; j++) {
                // Add current number to the respective set
                if (nums[j] % 2 == 0) {
                    distinctEvens.insert(nums[j]);
                } else {
                    distinctOdds.insert(nums[j]);
                }
                
                // 4. Check validity
                if (distinctEvens.size() == distinctOdds.size()) {
                    // Update max length (j - i + 1)
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
};