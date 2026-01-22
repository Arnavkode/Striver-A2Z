class Solution {
public:

    int helper(vector<int> & nums, int goal){
        if(goal < 0) return 0;
        int left= 0;
        int ans= 0;
        int curr = 0;

        for(int right = 0 ; right < nums.size() ; right++){

            curr += nums[right]%2;

            while(curr > goal){
                curr -= nums[left]%2;
                left++;
            } 

            ans += (right- left +1);

        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

    
        return helper(nums, k) - helper(nums, k-1);
    }
};

// again counting with subarrays

// /if i treat the number of odds as frequency? 
// with the help of a hash map
// prefix sum with the help of a hash map is kinda ass rntime wise
// slidign window, atmost(k) - atmost( k -1)
// kinda makes sense