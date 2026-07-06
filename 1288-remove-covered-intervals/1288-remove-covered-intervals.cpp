class Solution {
public:
    static bool comp(const vector<int> a,const vector<int> b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& inv) {
        int n=inv.size();
        int ans=n;
        sort(inv.begin(),inv.end(),comp);
        vector<int>t=inv[0];
        for(int i=1;i<n;i++){
            if(t[0]<=inv[i][0] && t[1]>=inv[i][1]){
                ans--;
            }
            else t=inv[i];
        }
        return ans;
    }
};