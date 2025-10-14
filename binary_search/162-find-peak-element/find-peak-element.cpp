class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();
        int low = 0;
        int high = n -1;
        int mid;
        
        if(n==1) return 0;

        while(low <= high){
            mid = (low+high)/2;
            if(mid == 0){
                if(nums[mid] > nums[mid+1]) return mid;
            }
            if(mid == n-1){
                if(nums[mid] > nums[mid-1]) return mid;
            }
            
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) return mid;

            if(nums[mid] < nums[mid+1]) low = mid+1;
            else high = mid-1;
        }

        return mid;

    }
};

// finding breaking point ya
