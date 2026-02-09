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
    vector<int> nodes;
    int maxdepth(TreeNode* root){
        if(root == nullptr) return 0;
        return 1 + max(maxdepth(root->left), maxdepth(root->right));
    }
    void fillArray(TreeNode* node){
        if(node == nullptr) return;
        fillArray(node->left);
        nodes.push_back(node->val);
        fillArray(node->right);
        return;
    }
    TreeNode* buildTree(vector<int> &nodes, int left, int right){
        if(left > right) return nullptr;
        int mid = (left + right)/2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = buildTree(nodes, left, mid-1);
        root->right = buildTree(nodes, mid+1, right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr)return root;
        fillArray(root);
        
        sort(nodes.begin(), nodes.end());

        return buildTree(nodes, 0, nodes.size()  -1);


    }
};

// to balance a binary searc tree, i need to convert it into an AVL tree 
// balancing would be when maxdepth - maxdepth right <= 1