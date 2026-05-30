class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inv) {
        sort(inv.begin(),inv.end(),[](const auto&a,const auto&b){
        return a[1]<b[1];
    });
        int ans=0;
        int prev_end=inv[0][1];
        for(int i=1;i<inv.size();i++){
            if(prev_end>inv[i][0]) ans++;
            else prev_end = inv[i][1];
        }
        return ans;
    }
};