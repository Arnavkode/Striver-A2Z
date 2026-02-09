/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode*& tgt, vector<TreeNode*> & path){
        if(!root) return false;
        path.push_back(root);
        if(root == tgt){

            return true;
        
        }
        
        if(findPath(root->left, tgt, path) ||findPath(root->right, tgt, path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        if (!findPath(root, p, path1) || !findPath(root, q, path2)) return nullptr;

        TreeNode* last = nullptr;
        for(int i = 0; i< min(path1.size(), path2.size()); i++){
            if(path1[i] == path2[i])
            {last = path2[i];}
            else
            break;
        }

        return last;
    }
};
// the first approach would be how i can just have a path finder
// find paths to both
// find the union and give the last common element back