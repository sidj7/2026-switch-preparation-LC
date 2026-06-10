class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        n=n*n;
        long long sn=(n*(n+1))/2;
        long long s2n=((long long)n*(n+1)*(2*n+1))/6;
        long long s=0,s2=0;
        for(auto i:grid){
            for(int j:i){
                s+=j;
                s2+=(long long)j*j;
            }
        }

        long long val1=s-sn;
        long long val2=s2-s2n;

        val2=val2/val1;
        long long x=(val1+val2)/2;
        long long y=val2-x;

        return {(int)x,(int)y};
    }
};