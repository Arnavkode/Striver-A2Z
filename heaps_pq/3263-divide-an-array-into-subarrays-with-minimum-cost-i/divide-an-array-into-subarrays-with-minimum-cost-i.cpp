class Solution {
public:
    int minimumCost(vector<int>& nums) {
        

        int min1 = 51;
        int min2 = 52;

        for(int i = 1; i< nums.size() ; i++){
            if(nums[i] < min1){min2 = min1; min1 = nums[i];}
            else if(nums[i] >= min1 && nums[i] < min2) min2 = nums[i];
        }

        return nums[0] + min1 + min2;
    } 
};

// nums arra
// cost of the array is its the first value
// divide nums into 3 disjoint contiguous subarryas
// need to give the least possible sum
// so basically need to give the sum of the 3 most minimum 
// and the first element always HAS TO BE THERE