class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>ans(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int s=q.front().second;
            ans[r][c]=s;

            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                int ns=s+1;
                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                if(!vis[nr][nc]){
                    q.push({{nr,nc},ns});
                    vis[nr][nc]=true;
                }
            }
        }
        return ans;
    }
};