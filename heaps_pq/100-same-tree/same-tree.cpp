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
    bool issamenode(TreeNode*p, TreeNode* q){
        if(p == nullptr && q) return false;
        if(q == nullptr && p) return false;
        if(p == nullptr && q == nullptr) return true;
        
        if(p -> val == q->val){
            return (issamenode(p->left, q->left) && issamenode(p->right, q->right));
        }
        else return false;
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return issamenode(p,q);
    }
};