class Solution {
public:
    void helper(vector<int>& candidates,vector<int> &subs, int diff,  int iter, vector<vector<int>> & ans){

        //let the decision be if i want to sub the current or move to the next
        // criteria should be if the remaining exists in the candidates, but 5 wouldnt exist in the
        // candidates but 2 and 3 do
        // i can kind of create a map of every difference out there cuz the 2^n would be regardless
        // or call a function to find if the current exist or no
        if(iter == candidates.size()) return;
        if(diff < 0) return;
        if(diff == 0){
            ans.push_back(subs);
            return;
            // if found then target should be rest and we should just move forward?
            // but this wouldnt do much would it?

        }

        subs.push_back(candidates[iter]);
        helper(candidates, subs, diff - candidates[iter], iter ,ans); //took curr and kept here
        // helper(candidates, subs, diff - candidates[iter],  iter + 1 ,ans);//took curr but moved fwd
        
        subs.pop_back();
        helper(candidates, subs, diff, iter + 1 ,ans);//didnt take curr and moved forward
        return;



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subs;
        helper(candidates, subs, target, 0 ,ans);
        return ans;
    }
};

// hint : recursion
// need to return combinations of candidates (can be used multiple times)
// that make up the target on sum
// feels like prefix sum
// create a freq map ig?
