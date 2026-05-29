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
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board;
        vector<vector<string>>ans;
        string s="";
        for(int i =0;i<n;i++) s+='.';
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        check(0,n,board,ans);
        return ans;

    }
};