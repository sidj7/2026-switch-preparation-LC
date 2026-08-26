class Solution {

private:
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
public:
    void dfs(int r,int c,vector<vector<bool>>&vis,vector<vector<char>>&board,int n,int m){
        vis[r][c]=true;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nr<n  && nc>=0 && nc<m && board[nr][nc] == 'O' && !vis[nr][nc]){
                dfs(nr,nc,vis,board,n,m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            if(i==0 || i==n-1){
                for(int j=0;j<m;j++){
                    if(!vis[i][j] && board[i][j]=='O'){
                        dfs(i,j,vis,board,n,m);
                    }
                }
            }
            else{
                if(!vis[i][0] && board[i][0]=='O') dfs(i,0,vis,board,n,m);
                if(!vis[i][m-1] && board[i][m-1]=='O')dfs(i,m-1,vis,board,n,m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};