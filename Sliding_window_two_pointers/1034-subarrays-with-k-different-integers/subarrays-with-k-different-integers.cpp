class Solution {
public:

    int helper(vector<int>& nums, int k){
        if(k<0) return 0;
        unordered_map<int, int> freq;

        int left = 0;
        // concepts of findig the smallest array with k diff numebrs
        int ans = 0;
        for(int right = 0 ; right < nums.size() ; right++){
            freq[nums[right]]++;

            while(freq.size() > k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }

            ans += left;

        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return helper(nums, k -1) - helper(nums, k);
        
    }
};

// integer array given nums, and the integer k
// number of diff integers should be exactly equal to k
// number of good subarrays asked
// can apply atmost rules here cuz to get exact i might have to subtract k-1 subarrays from k