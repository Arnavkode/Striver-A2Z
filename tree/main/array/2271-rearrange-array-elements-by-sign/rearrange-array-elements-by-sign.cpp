class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[pos] = nums[i];  // place positive at even index
                pos += 2;
            } else {
                ans[neg] = nums[i];  // place negative at odd index
                neg += 2;
            }
        }
        return ans;

        
    }
};