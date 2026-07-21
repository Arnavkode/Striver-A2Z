class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxlen = 0;
        int len = 0;
        int left= 0;
        int ans;
                for(int i =0 ; i < nums.size() ;){
            if(nums[i] == nums[left]){
                len++;
                i++;
            }else{
                if(maxlen < len){
                    maxlen = len;
                    ans = nums[left];
                }
                len = 0;
                left= i;
            }
        }
        if(maxlen < len){
                    maxlen = len;
                    ans = nums[left];
                }
        return ans;
    }
};