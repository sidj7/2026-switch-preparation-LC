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

    void ride(TreeNode* root, vector<int>&arr){
        if(!root) return;

        ride(root->left,arr);
        arr.push_back(root->val);
        ride(root->right,arr);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<int>inorder;
        ride(root,inorder);
        int n=q.size();
        int m=inorder.size();
        vector<vector<int>>ans(n,vector<int>(2,-1));
        for(int i=0;i<n;i++){
            int k=lower_bound(inorder.begin(),inorder.end(),q[i]) - inorder.begin();
            if (k < m) {
                ans[i][1] = inorder[k];
                if (inorder[k] == q[i]) {
                    ans[i][0] = inorder[k];
                    continue; 
                }
            }
            if (k > 0) {
                ans[i][0] = inorder[k - 1];
            }
        }
        return ans;
    }
};