class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
    

        int left = 0;
        int ans = 0;
        int nzeroes = 0;
        for(int right = 0; right < nums.size() ; right++){
            

            if(nums[right] == 0){
                nzeroes++;
            }

            while(nzeroes > k){
                if(nums[left] == 0){
                    nzeroes--;
                }
                left++; //move regardless you just need to reduce nzeroes

            }

            ans = max(ans, right- left + 1);
        }

        return ans;
        
    }
};

// the array has 0s and 1s, so its like if i need to get the maximum number of 1
// that i could get after flipping asw
// i think the i need to mind the gaps
// as i count 0s in  between ones
// and i can register it a s local answer if th enumber of zeroes is either less than or equal to my k

