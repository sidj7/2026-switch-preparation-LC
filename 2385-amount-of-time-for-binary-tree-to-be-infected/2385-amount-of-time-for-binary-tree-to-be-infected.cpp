class Solution {
public:
    TreeNode* make_parent(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* root, int target) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* t = nullptr;
        while (!q.empty()) {
            TreeNode* p = q.front(); q.pop();
            if (p->val == target) t = p;
            if (p->left) {
                q.push(p->left);
                parent[p->left] = p;
            }
            if (p->right) {
                q.push(p->right);
                parent[p->right] = p;
            }
        }
        return t;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* target = make_parent(parent, root, start);
        
        // OPTIMIZATION 1: Use unordered_set instead of ordered map for O(1) lookups
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        
        q.push(target);
        vis.insert(target);
        int level = -1;
        
        while (!q.empty()) {
            int n = q.size();
            level++;
            for (int i = 0; i < n; i++) {
                TreeNode* p = q.front(); q.pop();
                
                if (p->left && !vis.count(p->left)) {
                    q.push(p->left);
                    vis.insert(p->left);
                }
                if (p->right && !vis.count(p->right)) {
                    q.push(p->right);
                    vis.insert(p->right);
                }
                // OPTIMIZATION 2: Use .count() to prevent silent map insertions
                if (parent.count(p) && !vis.count(parent[p])) {
                    q.push(parent[p]);
                    vis.insert(parent[p]);
                }
            }
        }
        return level;
    }
};