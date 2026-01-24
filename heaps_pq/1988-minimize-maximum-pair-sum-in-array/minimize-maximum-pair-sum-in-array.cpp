class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int left =0 ;
        int right = nums.size() -1;

        int ans = 0;

        while(left < right){
            ans = max(ans , nums[left] + nums[right]);
            left++;
            right--;
        }

        return ans;

        //this approach wouldnt work on duplicated elements
        // lets try an exhaustive method
        // recursive
        // or iterative

        // two pointers only, need to take alast and first at every iteration and just try to maintain a maxi
    }
};
// given an array of even lenghth n
// pairs banani hai from the given array such that the maximum pair sum jo hota vo minimise ho gaya hai
// thats like pairing up the maximum and minmum element at each turn