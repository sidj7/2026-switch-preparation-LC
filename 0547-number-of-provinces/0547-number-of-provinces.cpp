class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis) {
        vis[node] = true;
        
        // Traverse all possible neighbors directly from the matrix
        for (int j = 0; j < isConnected.size(); j++) {
            // If there is an edge AND the neighbor isn't visited yet
            if (isConnected[node][j] == 1 && !vis[j]) {
                dfs(j, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int ans = 0;

        // Stick to 0-based indexing
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, isConnected, vis);
                ans++;
            }
        }
        return ans;
    }
};