class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int fresh_oranges=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=true;
                }
                else if(grid[i][j]==1){
                    fresh_oranges++;
                }
            }
        }
        if(!fresh_oranges) return 0;
        int ans=-1;

        while(!q.empty()){
            int k=q.size();
            ans++;

            for(int i=0;i<k;i++){
                int f=q.front().first;
                int s=q.front().second;

                q.pop();

                if(f-1 >= 0 && f-1 < n && s >= 0 && s < m && !vis[f-1][s] && grid[f-1][s]==1){
                    q.push({f-1,s});
                    vis[f-1][s]=true;
                    grid[f-1][s]=2;
                    fresh_oranges--;
                }
                if(f+1 >= 0 && f+1 < n && s >= 0 && s < m && !vis[f+1][s] && grid[f+1][s]==1){
                    q.push({f+1,s});
                    vis[f+1][s]=true;
                    grid[f+1][s]=2;
                    fresh_oranges--;
                }
                if(f >= 0 && f < n && s-1 >= 0 && s-1 < m && !vis[f][s-1] && grid[f][s-1]==1){
                    q.push({f,s-1});
                    vis[f][s-1]=true;
                    grid[f][s-1]=2;
                    fresh_oranges--;
                }
                if(f >= 0 && f < n && s+1 >= 0 && s+1 < m && !vis[f][s+1] && grid[f][s+1]==1){
                    q.push({f,s+1});
                    vis[f][s+1]=true;
                    grid[f][s+1]=2;
                    fresh_oranges--;
                }
            }
        }

        if(fresh_oranges) return -1;
        return ans;
    }
};