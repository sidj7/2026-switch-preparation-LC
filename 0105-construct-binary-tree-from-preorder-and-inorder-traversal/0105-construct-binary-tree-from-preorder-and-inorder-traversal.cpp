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

    TreeNode* build(vector<int>& po,int i, int n,vector<int>& io,int j,int m,map<int,int>&mp){
        if(i>n || j>m ) return NULL;

        TreeNode * root = new TreeNode(po[i]);
        int in_root = mp[po[i]];
        int num_left=in_root-j;

        root->left = build(po,i+1,i+num_left,io,j,in_root-1,mp);
        root->right = build(po,i+num_left+1,n,io,in_root+1,m,mp);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        int n=preorder.size();
        int m=inorder.size();
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        TreeNode*root=build(preorder,0,n-1,inorder,0,m-1,mp);
        return root;
    }
};