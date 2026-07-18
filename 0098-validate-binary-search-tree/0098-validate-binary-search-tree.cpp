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
    bool check(TreeNode* root, long s,long e){
        if(!root) return true;

        long data= (long)root->val;
        if(data >= e || data <= s) return false;
        bool l = check(root->left, s ,data);
        bool r = check(root->right, data ,e);
        
        return l&r;
    }

    bool isValidBST(TreeNode* root) {
        long s=LONG_MIN;
        long e=LONG_MAX;
        return check (root,s,e);
    }
};