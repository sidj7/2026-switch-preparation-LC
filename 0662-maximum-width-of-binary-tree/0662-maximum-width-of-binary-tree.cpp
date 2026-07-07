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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            int mn = q.front().second;
            for(int i=0;i<n;i++){
                int id=q.front().second-mn;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==n-1) ans=max(ans,id+1);
                if(node->left) q.push({node->left,(long long)id*2+1});
                if(node->right) q.push({node->right,(long long)id*2+2});
            }
        }
        return ans;
    }
};