class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        int high = n-1;
        int low = 0;

        while(n--){
            if(nums[low] != target) low++;
            if(nums[high] != target) high--;
        }

        if(high < low) return {-1,-1};
        else  return{low, high};


        
    }
};

// nums sorted in ascending order
// find starteing and ending position, first time it occurred and last time it occurred
// return {-1, -1} if nothign found

// O(longn) means binary search
// if mid == target, mid + 1?
// lets just have high and low