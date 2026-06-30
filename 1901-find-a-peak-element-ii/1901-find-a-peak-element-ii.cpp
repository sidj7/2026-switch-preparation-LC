class Solution {
public:
    int find(vector<vector<int>>& arr,int c){
        int ans=0,idx=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i][c]>ans){
                ans=arr[i][c];
                idx=i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int l=0,h=m-1;
        pair<int,int>ans;
        while(l<=h){
            int c=l+(h-l)/2;

            int r=find(mat,c);

            int left=c>0?mat[r][c-1]:-1;
            int right = c<m-1?mat[r][c+1]:-1;

            if(mat[r][c]>left && mat[r][c]>right){
                return {r,c};
            }
            else if(mat[r][c]<left){
                h=c-1;
            }
            else l=c+1;
        }
        return {-1,-1};
    }
};