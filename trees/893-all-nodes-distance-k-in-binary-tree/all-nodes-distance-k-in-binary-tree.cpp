class Solution {
public:
    // Helper to build parent pointers
    void mapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if(curr->left) {
                parents[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                parents[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        mapParents(root, parents); // Step 1: Build graph connectivity
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        // Start BFS from target
        q.push(target);
        visited[target] = true;
        int dist = 0;
        
        while(!q.empty()) {
            if(dist == k) break; // We found the layer!
            dist++;
            
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front(); q.pop();
                
                // Try all 3 directions
                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parents[curr] && !visited[parents[curr]]) { // Go UP
                    q.push(parents[curr]);
                    visited[parents[curr]] = true;
                }
            }
        }
        
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};