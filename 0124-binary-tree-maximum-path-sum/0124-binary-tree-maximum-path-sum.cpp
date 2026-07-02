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

    int func(TreeNode* root, int & ans){
        if(!root) return 0;

        int l=func(root->left,ans);
        l= l<0 ? 0 :l;
        int r=func(root->right,ans);
        r= r<0 ? 0:r;
        ans=max(ans,(root->val)+l+r);

        return root->val+max(l,r);

    }

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int t=func(root,ans);
        return ans;
    }
};