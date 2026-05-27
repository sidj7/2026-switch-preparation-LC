class Solution {
public:

    void func (int i,int n,vector<int>c,int t,vector<vector<int>>&ans,vector<int>d){
        if(t<0) return;
        if(i==n){
            if(t==0){
                ans.push_back(d);
            }
            return;
        }

        d.push_back(c[i]);
        func(i,n,c,t-c[i],ans,d);
        d.pop_back();
        func(i+1,n,c,t,ans,d);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>>ans;
        vector<int>d;
        int n=c.size();
        func(0,n,c,t,ans,d);
        return ans;
    }
};