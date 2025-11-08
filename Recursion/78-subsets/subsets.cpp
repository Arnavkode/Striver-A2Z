class Solution {
public:

    void helper(vector<int>& s, vector<int>& nums,int tries,  vector<vector<int>>& ans){
        if(tries == nums.size()){
            ans.push_back(s);
            return;
        }
        s.push_back(nums[tries]);
        helper(s, nums, ++tries, ans);
        tries--;
        s.pop_back();
        helper(s, nums,++tries , ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int tries = 0;
        vector<int> s;
        helper(s, nums, tries, ans);
        return ans;
    }
};

// aight
// need to form a set of all subsets
// decision is to take aor not to take, simple


// TC = O(N) maximum depth
// SC = O