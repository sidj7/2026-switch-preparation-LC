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
    void recoverTree(TreeNode* root) {
        TreeNode *f = NULL, *m = NULL, *l = NULL, *p = NULL, *cur = root;
        cur=root;
        while(cur){
            if(!cur->left){
                if(p && cur->val < p->val){
                    if(!f){
                        f=p;
                        m=cur;
                    }
                    else l=cur;
                }
                p=cur;
                cur=cur->right;
            }
            else{
                TreeNode* pre=cur->left;
                while(pre->right && pre->right != cur) pre=pre->right;
                if(!pre->right){
                    pre->right=cur;
                    cur=cur->left;
                }
                else{
                    if(p && cur->val < p->val){
                    if(!f){
                        f=p;
                        m=cur;
                    }
                    else l=cur;
                    }
                    pre->right=NULL;
                    p=cur;
                    cur=cur->right;
                }
            }
        }
        if(f && l) swap(f->val,l->val);
        else if(f && m) swap(f->val,m->val);
    }
};