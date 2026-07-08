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
    void make_parent(TreeNode* root , unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* p=q.front() ; q.pop();
            if(p->left){
                    q.push(p->left);
                    parent[p->left]=p;
            }
            if(p->right){
                    q.push(p->right);
                    parent[p->right]=p;
                }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        map<TreeNode*,bool>vis;
        make_parent(root,parent);
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int level=0;
        while(!q.empty()){
            int n=q.size();
            if(level++ == k) break;
            for(int i=0;i<n;i++){
                TreeNode* p =q.front();q.pop();

                if(p->left && !vis[p->left]){
                    q.push(p->left);
                    vis[p->left]=true;
                }
                if(p->right && !vis[p->right]){
                    q.push(p->right);
                    vis[p->right]=true;
                }
                if(parent[p] && !vis[parent[p]]){
                    q.push(parent[p]);
                    vis[parent[p]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* p=q.front();q.pop();
            ans.push_back(p->val);
        }
        return ans;
    }
};