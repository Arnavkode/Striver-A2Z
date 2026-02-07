/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void sideView(TreeNode* root, int row,  map<int,vector<int>> & ans){
        if(root== nullptr) return;
        ans[row].push_back(root->val);
        
            sideView(root->right,row+1, ans);
            sideView(root->left,row+1, ans);
    
        return ;
    }

    vector<int> rightSideView(TreeNode* root) {
        map<int,vector<int>>mp;
        sideView(root,0, mp);
        vector<int> ans;
        for(auto p : mp){
            ans.push_back(p.second[0]);
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};

// at any level just try to have the rightmost node possible
// need to find the rightmost(or most recent) entry to a row