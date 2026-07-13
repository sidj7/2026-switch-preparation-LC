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
    // tc - O(N) || sc - O(N) {recursion stack-space} || [right->left->root]
    // TreeNode*prev=NULL;
    // void flatten(TreeNode* root) {
    //     if(!root) return;

    //     flatten(root->right);
    //     flatten(root->left);

    //     root->right=prev;
    //     root->left=NULL;
    //     prev=root;
    // }

    // tc - O(N) || sc - O(N) {stack} [right,left,root]
    // void flatten(TreeNode* root) {
    //     if(!root) return;
    //     stack<TreeNode*>st;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode* cur = st.top() ; st.pop();

    //         if(cur->right) st.push(cur->right);

    //         if(cur->left) st.push(cur->left);

    //         if(!st.empty()) cur->right = st.top();

    //         cur->left = NULL;
    //     }
    // }

    void flatten(TreeNode* cur) {
        if(!cur) return;
        TreeNode* root=cur;
        while(root){
            if(root->left){
                TreeNode*prev=root->left;
                while(prev->right) prev=prev->right;
                prev->right=root->right;
                root->right= root->left;
                root->left=NULL;
            }
            root=root->right;
        }
    }

};