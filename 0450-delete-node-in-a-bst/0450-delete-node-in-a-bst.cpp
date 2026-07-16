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
    TreeNode* findMin(TreeNode* root){
        while(root && root->left) root=root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(key > root->val) root->right = deleteNode(root->right,key);
        else if(key < root->val) root->left = deleteNode(root->left,key);
        else{
            if(!root->left){
                TreeNode* t = root->right;
                delete root;
                return t;
            }
            else if(!root->right){
                TreeNode* t = root->left;
                delete root;
                return t;
            }
            else{
                TreeNode* t = findMin(root->right);
                root->val = t->val;
                root->right = deleteNode(root->right,t->val);
            }
        }
        return root;
    }
};