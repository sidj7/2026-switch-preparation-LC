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
    int lh(TreeNode* root){
        int ht=0;
        while(root){
            root=root->left;
            ht++;
        }
        return ht;
    }
    int rh(TreeNode* root){
        int ht=0;
        while(root){
            root=root->right;
            ht++;
        }
        return ht;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int l=lh(root);
        int r=rh(root);

        if(l==r) return (1<<l)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};