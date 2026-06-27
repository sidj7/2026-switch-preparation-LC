class Solution {
public:

    int func(vector<vector<int>>& mat,int c,int r){
        int el=INT_MIN;
        int ans=-1;
        for(int i=0;i<r;i++){
            if(mat[i][c]>el){
                el=mat[i][c];
                ans=i;
            }
        }
        return ans;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int l=0,h=m-1;

        while(l<=h){

            int md=(l+h)/2;

            int r=func(mat,md,n);

            int left=md-1>=0?mat[r][md-1]:-1;
            int right=md+1<m?mat[r][md+1]:-1;

            if(mat[r][md]>left && mat[r][md]>right) return {r,md};

            else if(mat[r][md]<right)l=md+1;
            else h=md-1; 

        }

        return {-1,-1};
    }
};