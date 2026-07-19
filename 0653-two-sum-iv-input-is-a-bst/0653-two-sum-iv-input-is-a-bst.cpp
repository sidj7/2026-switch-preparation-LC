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

class bstiter{
private:
    stack<TreeNode*>st;
    bool rev;

    void pushnode(TreeNode* node){
        while(node){
            if(rev){
                st.push(node);
                node=node->right;
            }
            else{
                st.push(node);
                node=node->left;
            }
        }
    }
public:
    bstiter(TreeNode* root, bool isrev){
        rev=isrev;
        pushnode(root);
    }

    int next(){
        TreeNode* t= st.top();
        st.pop();
        if(rev) pushnode(t->left);
        else pushnode(t->right);
        return t->val;
    }

};



class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        bstiter l(root,0);
        bstiter r(root,1);

        int i=l.next();
        int j=r.next();

        while(i<j){
            if(i+j==k) return true;

            if(i + j > k) j=r.next();

            else i=l.next();
        }
        return false;

    }
};