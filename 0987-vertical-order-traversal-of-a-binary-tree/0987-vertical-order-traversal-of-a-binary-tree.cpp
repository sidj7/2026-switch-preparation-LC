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

    void drive(TreeNode* root,map<int,vector<pair<int,int>>>&mp,int x,int y){
        if(!root) return;

        mp[x].push_back({root->val,y});

        if(root->left) drive(root->left,mp,x-1,y+1);
        if(root->right) drive(root->right,mp,x+1,y+1);
    }
    static bool comp(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second; // Sort by depth ascending
    }   

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;

        drive(root,mp,0,0);
        vector<vector<int>>ans;
        for(auto &i:mp){
            sort(i.second.begin(),i.second.end(),comp);
            vector<int>t;
            for(auto j:i.second) t.push_back(j.first);
            ans.push_back(t);
        }

        return ans;
    }
};