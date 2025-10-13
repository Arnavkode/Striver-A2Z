class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();

        int low = 0;
        int high = n-1;
        int mid;
        for(int i = 0; i<n; i++){
            mid = (low +high)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) high = mid;
            else low = mid+ 1;
        }
        return low;
}
};

// O(logn) means Binary search lagaooo
// its asking for the index where it wouldve been
// basically the mid
// because mid points to the tentative pplace where an elemnt shouldve and could be
// answer would be low, mid and high
// low and high cant be it cuz after zoning down, its either low or high that could be at the extremes
// mid is our only bet?