class Solution {
public:

    void func(int ind,int n,int k,vector<int>t,vector<vector<int>>&ans){
       if(k==0){
        ans.push_back(t);
        return;
       }

       for(int i=ind;i<=n;i++){
        t.push_back(i);
        func(i+1,n,k-1,t,ans);
        t.pop_back();
       }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>t;
        func(1,n,k,t,ans);
        return ans;
    }
};