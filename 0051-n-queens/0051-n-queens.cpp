class Solution {
public:
    bool issafe(int r,int c,int n,vector<string>board){

        int dr=r,dc=c;

        while(dr>=0 && dc>=0){
            if(board[dr][dc] == 'Q') return false; 
            dr--;dc--;
        }

        dr=r;dc=c;
        while(dc>=0){
            if(board[dr][dc] == 'Q') return false;
            dc--;
        }

        dr=r;dc=c;
        while(dr<n && dc>=0){
            if(board[dr][dc] == 'Q') return false;
            dr++;dc--;
        }

        return true;
    }

    void check(int c,int n,vector<string>board,vector<vector<string>>&ans){
        if(c==n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(issafe(i,c,n,board)){
                board[i][c]='Q';
                check(c+1,n,board,ans);
                board[i][c]='.';
            }
        }
    }

    void check2(int c,int n,vector<string>board,vector<vector<string>>&ans,vector<bool>ud,vector<bool>lr,vector<bool>dd){

        if(c==n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(!ud[n-1+c-i] && !lr[i] && !dd[i+c]){
                board[i][c] = 'Q';
                ud[n-1+c-i]=true;
                lr[i]=true;
                dd[i+c]=true;
                check2(c+1,n,board,ans,ud,lr,dd);
                board[i][c] = '.';
                ud[n-1+c-i]=false;
                lr[i]=false;
                dd[i+c]=false;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string>board;
        vector<vector<string>>ans;
        string s="";
        for(int i =0;i<n;i++) s+='.';
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        //check(0,n,board,ans);
        vector<bool>updiag(2*n-1,false),lr(n,false),lowdiag(2*n-1,false);
        check2(0,n,board,ans,updiag,lr,lowdiag);


        return ans;

    }
};