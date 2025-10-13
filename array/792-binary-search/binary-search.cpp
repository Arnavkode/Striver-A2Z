class Solution {
public:
    int search(vector<int>& nums, int target) {

        int high = nums.size();
        int low = 0;
        int mid;
        while(low<high){

            mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target ) high = mid;
            else low = mid+ 1;
            
        }

        return -1;
        
    }
};