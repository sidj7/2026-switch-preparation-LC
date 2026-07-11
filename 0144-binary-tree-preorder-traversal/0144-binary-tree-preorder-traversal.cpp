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

 //Using MORRIS Iterative method O(n), O(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return {};
        if(!root->left && !root->right) return {root->val};

        TreeNode* cur = root;

        while(cur){
            if(!cur->left){
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode * prev = cur->left;
                while(prev->right && prev->right!=cur) prev=prev->right;
                if(!prev->right){
                    prev->right = cur;
                    ans.push_back(cur->val);
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};