class Solution {
public:

    void dfs(vector<vector<int>>&img,int r,int c,int oc,int nc,vector<vector<bool>>&vis,int n,int m){
        vis[r][c]=true;
        img[r][c]=nc;

        if(r-1<n && r-1>=0 && c<m && c>=0 && img[r-1][c]==oc && !vis[r-1][c]){
            dfs(img,r-1,c,oc,nc,vis,n,m);
        }
        if(r+1<n && r+1>=0 && c<m && c>=0 && img[r+1][c]==oc && !vis[r+1][c]){
            dfs(img,r+1,c,oc,nc,vis,n,m);
        }
        if(r<n && r>=0 && c-1<m && c-1>=0 && img[r][c-1]==oc && !vis[r][c-1]){
            dfs(img,r,c-1,oc,nc,vis,n,m);
        }
        if(r<n && r>=0 && c+1<m && c+1>=0 && img[r][c+1]==oc && !vis[r][c+1]){
            dfs(img,r,c+1,oc,nc,vis,n,m);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int new_c) {
        int old_c=image[sr][sc];
        int n=image.size();
        int m=image[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        if(image[sr][sc]!= new_c) dfs(image,sr,sc,old_c,new_c,vis,n,m);

        return image;
    }
};