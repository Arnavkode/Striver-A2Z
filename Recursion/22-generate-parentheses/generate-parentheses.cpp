class Solution {
public:

    void helper(string s, int open, int closed, int pairs, vector<string> & ans ){
        if(open == closed && open == pairs){
            ans.push_back(s);
            return;
        }
        if(open > closed && open < pairs){
            helper(s + '(', open +1, closed, pairs, ans);
            helper(s + ')', open, closed + 1, pairs, ans);

        }
        if(open == closed && open < pairs){
            helper(s + '(', open +1, closed, pairs, ans);
        }
        if(open > closed && open == pairs){
            helper(s + ')', open , closed + 1, pairs, ans);

        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s ;
        helper(s , 0, 0, n , ans);
        return ans;
    }
};

// given n pairs
// need to return all the well formed parantheses
// niggas used stack?
// stack is just a data struncture to store the parantheses can be mimicked with a string