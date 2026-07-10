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
    TreeNode* build(vector<int>& inorder,int istart,int iend, vector<int>& postorder,int pstart,int pend, map<int,int>&mp){
        if(istart>iend || pstart>pend) return NULL;

        TreeNode* root = new TreeNode(postorder[pend]);

        int in_root = mp[postorder[pend]];
        int numleft = in_root-istart;

        root->left = build(inorder,istart,in_root-1,postorder,pstart,pstart+numleft-1,mp);
        root->right = build(inorder,in_root+1,iend, postorder,pstart+numleft,pend-1,mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int m=postorder.size();

        map<int,int>mp;
        for(int i=0;i<n;i++)mp[inorder[i]]=i;

        TreeNode* root = build(inorder,0,n-1,postorder,0,m-1,mp);

        return root;
    }
};