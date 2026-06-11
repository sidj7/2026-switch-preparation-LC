class Solution {
public:

    void check(int c,int n,vector<vector<string>>&ans,vector<string>&board,vector<bool>&lr,vector<bool>&ud,vector<bool>&ld){
        if(c==n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(!lr[i] && !ud[n-1+c-i] && !ld[i+c]){
                board[i][c]='Q';
                lr[i]=true;
                ld[i+c]=true;
                ud[n-1+c-i]=true;
                check(c+1,n,ans,board,lr,ud,ld);
                lr[i]=false;
                ld[i+c]=false;
                ud[n-1+c-i]=false;
                board[i][c]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        vector<bool>lr(n,false),ud(2*n-1,false),ld(2*n-1,false);
        check(0,n,ans,board,lr,ud,ld);
        return ans;
    }
};