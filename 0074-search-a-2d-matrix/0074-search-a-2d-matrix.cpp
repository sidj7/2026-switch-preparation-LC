class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n=mat.size();
        int m=mat[0].size();

        int l=0,h=n*m-1;
        while(l<=h){
            int md=(l+h)/2;

            int x=md/m;
            int y=md%m;

            if(mat[x][y]==t) return true;

            if(mat[x][y]>t) h=md-1;
            else l=md+1;
        }
        return false;
    }
};