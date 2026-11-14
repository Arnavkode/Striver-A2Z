class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int decmax = 0;
        int incmax = 0;
        int inc = 0;
        int dec = 0;

        for(int i = 1 ;i < nums.size(); i++){
            if(nums[i] > nums[i-1]){ inc++;
            dec = 0;
            }
            if(nums[i] < nums[i-1]){
                dec++;
                inc = 0;
            }
            if(nums[i] == nums[i-1]){
                inc = 0;
                dec = 0;

            }
            incmax = max(incmax, inc);
            decmax = max(decmax, dec);
        }

        return max(incmax, decmax) +1;
    }
};