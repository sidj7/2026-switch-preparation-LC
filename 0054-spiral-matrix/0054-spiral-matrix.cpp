class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
       int m=mat.size();
       int n=mat[0].size();
       int t=0,l=0,r=n-1,d=m-1;
       vector<int>ans;
       while(t<=d && l<=r){
        for(int i=l;i<=r;i++){
            ans.push_back(mat[t][i]);
        }
        t++;
        for(int i=t;i<=d;i++){
            ans.push_back(mat[i][r]);
        }
        r--;

        if(t<=d){
            for(int i=r;i>=l;i--){
                ans.push_back(mat[d][i]);
            }
            d--;
        }
        if(l<=r){
            for(int i=d;i>=t;i--){
                ans.push_back(mat[i][l]);
            }
            l++;
        }
       }
       return ans;
    }
};