class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // two pointer 
        vector<pair<int,int>> twonums;
        for(int i = 0 ; i < nums.size() ; i++){
            twonums.push_back({nums[i], i});

        }

        sort(twonums.begin(),  twonums.end());
        int n = nums.size();
        int left = 0;
        int right = n- 1;

        while(left < right){
            int sum = twonums[left].first + twonums[right].first;

            if(sum == target){
                return {twonums[left].second, twonums[right].second};
            }else if (sum > target) right --;
            else left ++;
        }

        return {left, right};
    }
};