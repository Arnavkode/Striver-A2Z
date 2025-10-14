class Solution {
public:

    int binary(vector<int>& nums, int target, bool first){
        int n = nums.size();
        int low = 0;
        int high= n-1;
        int mid;
        int ans = -1; //index
        while(low<=high){
            mid = (low+ high)/2;
            if(nums[mid] == target){
                if(first){
                    ans = mid;
                    high = mid-1; //look further left while stroing the current found
                    continue;
                }
                else{
                    ans = mid;
                    low= mid+1; //look further right while storing the current found
                    continue;
                }
            }
            if(nums[mid]>target) high = mid-1;
            else low = mid + 1;
            
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> res;
        res.push_back(binary(nums, target, true));
        res.push_back(binary(nums,target,false));

        return res;
       
    }
};

// nums sorted in ascending order
// find starteing and ending position, first time it occurred and last time it occurred
// return {-1, -1} if nothign found

// O(longn) means binary search
// if mid == target, mid + 1?
// lets just have high and low

// hint: run binary search twice
// im hoping one to figure the first element out and the second to the last
// we can find the element and shuffle to the last in the return condn of binary search

// im a dumbfuck
// two binary search help such that if i want to find the start
// i keep looking at the left
// if i want to find the end, i keep looking at the right