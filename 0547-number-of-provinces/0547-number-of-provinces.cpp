class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj,vector<bool>&vis){
        vis[node]=true;

        for(int i:adj[node]){
            if(!vis[i]) dfs(i,adj,vis);
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && !isConnected[i][j]) continue;
                adj[i+1].push_back(j+1);
                adj[j+1].push_back(i+1);
            }
        }
        vector<bool>vis(n,false);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};