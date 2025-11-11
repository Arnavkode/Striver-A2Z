class Solution {
public:
    void helper(vector<int>& candidates,int diff, int iter, vector<int> & subs, vector<vector<int>> & ans){
       
        if(diff < 0) return;
        if(diff == 0){
            ans.push_back(subs);
            return;
        }
         if(iter  >= candidates.size()) return;
        
        subs.push_back(candidates[iter]);
        helper(candidates, diff - candidates[iter], iter + 1, subs, ans);
        subs.pop_back();
       int next_iter = iter + 1;
        while (next_iter < candidates.size() && candidates[next_iter] == candidates[iter]) {
            next_iter++;
        }
        helper(candidates, diff, next_iter, subs, ans);

        return;
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subs;
        vector<int> nums = candidates;
        sort(nums.begin(), nums.end());
        helper(nums, target, 0, subs, ans);
        return ans;

    }
};

// okay combintion sum but each can be sued only once
// so the decision comes to taking the current number and moving on or not taking the current number
// and also moving on