class Solution {
public:

    void func(int i,int n,int t,vector<int>d,vector<int>&c,vector<vector<int>>&ans){
        if(t==0){
            ans.push_back(d);
            return;
        }
        for(int idx=i;idx<n;idx++){
            if(idx>i && c[idx]==c[idx-1]) continue;
            if(t<c[idx]) break;
            d.push_back(c[idx]);
            func(idx+1,n,t-c[idx],d,c,ans);
            d.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>>ans;
        int n=c.size();
        sort(c.begin(),c.end());
        func(0,n,t,{},c,ans);
        return ans;
    }
};