/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string data="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* p= q.front(); q.pop();
            
            if(!p) data.append("#,");
            else{
                data.append(to_string(p->val)+',');
                q.push(p->left);
                q.push(p->right);
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")return NULL;

        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* p = q.front(); q.pop();

            getline(s,str,',');

            if(str=="#") p->left = NULL;
            else{
                TreeNode* node = new TreeNode(stoi(str));
                p->left=node;
                q.push(node);
            }

            getline(s,str,',');

            if(str=="#") p->right = NULL;
            else{
                TreeNode* node = new TreeNode(stoi(str));
                p->right=node;
                q.push(node);
            }
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));