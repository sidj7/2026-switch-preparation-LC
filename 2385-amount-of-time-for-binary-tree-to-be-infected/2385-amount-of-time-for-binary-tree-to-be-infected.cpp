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
    TreeNode* make_parent(unordered_map<TreeNode*,TreeNode*>&parent,TreeNode* root,int target){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* t=root;
        while(!q.empty()){
            TreeNode* p =q.front(); q.pop();
            if(p->val == target) t= p;
            if(p->left){
                q.push(p->left);
                parent[p->left]=p;
            }
            if(p->right){
                q.push(p->right);
                parent[p->right]=p;
            }
        }
        return t;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        TreeNode*target = make_parent(parent,root,start); //1 teer se 2 nishane- parent map , start node found;
        map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int level=-1;
        while(!q.empty()){
            int n=q.size();
            level++;
            for(int i=0;i<n;i++){
                TreeNode*p=q.front();q.pop();
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
        return level;
    }
};