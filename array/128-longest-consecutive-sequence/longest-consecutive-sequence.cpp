class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int counter = 1;

        for(int i =1 ; i <nums.size(); i++){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1] + 1) counter++;
            else{
                counter = 1;
            }
            
                longest = max(longest, counter);
        } 
        return longest;
    }
};

// longest subsequence required as in 1,2,3,4 or 76,77, 78
// sorting takes O(1)
// then apply two pointer?
// maintain a longest counter


// arrays edge cases:
// 1. the array can be empty
// 2. the array could have a single element