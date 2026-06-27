class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n=mat.size();
        int m=mat[0].size();
        int r=0,c=m-1;

        while(r<n && c>=0){
            if(mat[r][c]==t) return true;

            else if(mat[r][c]>t) c--;

            else r++;
        }
        return false;
    }
};