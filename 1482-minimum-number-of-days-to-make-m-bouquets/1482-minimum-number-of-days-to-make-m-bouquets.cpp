class Solution {
public:

    bool isval(vector<int>&bd,int m,int k,int md){
        
        int b=0,f=0;
        for(int i:bd){
            if(i<=md) f++;
            else{
                b+=(f/k);
                f=0;
            }
        }
        b+=(f/k);
        return b>=m ;
    }
    int minDays(vector<int>& bd, int m, int k) {
        if((long long)m*k>bd.size()) return -1;
        int mn=*min_element(bd.begin(),bd.end());
        int mx=*max_element(bd.begin(),bd.end());
        int ans=1e9+1;
        while(mn<=mx){
            int md=mn+(mx-mn)/2;

            if(isval(bd,m,k,md)){
                ans=min(ans,md);
                mx=md-1;
            }
            else{
                mn=md+1;
            }
        }
        return ans==1e9+1?-1:ans;
    }
};