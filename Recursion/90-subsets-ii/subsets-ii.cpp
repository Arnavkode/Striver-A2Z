class Solution {
public:
    void helper(vector<int>& nums, vector<int>& sub, int iter, vector<vector<int>>& ans){
        if(iter == nums.size()){
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[iter]);
        helper(nums, sub, iter + 1, ans);
        sub.pop_back();

        int next_iter = iter + 1;
        while(next_iter < nums.size() && nums[next_iter] == nums[iter]){
            next_iter++;
        }
        helper(nums, sub, next_iter, ans);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> sub;
sort(nums.begin(), nums.end());
        helper(nums, sub, 0, ans);
       sort(ans.begin(), ans.end());
        return ans;


        
    }
};

// the decision just pick one up and dont with the other
// must not contain duplicates??
// ill need to find if the subset has been done or no?
// could do a whole ass check after getting the ans once

// the correct logic is sort the array, pick the current number
// if the next is same just skip to the last
// would ensure no duplicate arrays.