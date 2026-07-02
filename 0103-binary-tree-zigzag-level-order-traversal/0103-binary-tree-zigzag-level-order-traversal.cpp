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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*>q;
        vector<vector<int>>ans;

        q.push(root);
        bool odd = true;
        while(!q.empty()){
            int n=q.size();
            vector<int>t(n);

            for(int i=0;i<n;i++){
                TreeNode* p=q.front();
                q.pop();
                if(odd){
                    t[i]=p->val;
                }
                else{
                    t[n-i-1]=p->val;
                }
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
            }
            odd=!odd;
            ans.push_back(t);
        }
        return ans;
    }
};