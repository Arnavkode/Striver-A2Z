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
    int maxdepth(TreeNode* root){
        if(root == nullptr) return 0;

        return 1 + max(maxdepth(root->left), maxdepth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // need to reach the extremes
        // and its max heigh left + maxheight right
        if(root == nullptr) return 0;

        return max(max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)), maxdepth(root->right) + maxdepth(root->left));
    }
};