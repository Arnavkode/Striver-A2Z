class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int left =0 ;
        int curr = 0;
        int ans = 0;
        unordered_map<int,int> odds; //number of adds against its frequency
        odds[0] =1;
        for(int right =0 ; right < nums.size() ; right++){

            if(nums[right] %2  == 1) curr++;
            odds[curr] ++;

            if(odds.count(curr - k)){
                ans+= odds[curr - k];
            }
            
            

        }
        return ans;
        
    }
};

// again counting with subarrays

// /if i treat the number of odds as frequency? 
// with the help of a hash map