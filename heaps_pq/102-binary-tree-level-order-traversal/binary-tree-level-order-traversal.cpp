/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // bfs - level order
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if (root)
            q.push(root);

        while (!q.empty()) {

            vector<int> level;
            int size = q.size();
            // simulates a level, clears all n level nodes, while adding n+1 level (their children)
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop(); // the parent is popped
                level.push_back(temp->val);
                // children are pushed
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};