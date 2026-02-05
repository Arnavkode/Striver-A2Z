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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if(root)q.push(root);
        int lvl = 0;

        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                    
                
                level.push_back(node->val);
               
            } 
            lvl++;
            if(lvl%2 == 0) reverse(level.begin(), level.end());
            ans.push_back(level);
        }

        return ans;
        
    }
};

// zig zag ke liye queue use karna rahega most probably
// get all the children, out them while inserting their kids in the stack
