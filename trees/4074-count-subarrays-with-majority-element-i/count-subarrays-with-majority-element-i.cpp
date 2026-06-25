class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
            int ans = 0;

        for(int i = 0 ; i < nums.size(); i++){
            int count  = 0;
            for(int j = i ; j < nums.size() ; j++){
                if(nums[j] == target) count++;
                if(count > floor((j- i + 1)/2.0)) ans++;
            }
        }
        return ans;
    }
};

// given integer array nums and an integer target
