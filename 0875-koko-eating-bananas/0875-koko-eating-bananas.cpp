class Solution {
public:
    bool isval(vector<int>&piles,int hr,int rate){
        long long cnthr=0;
        for(int i:piles){
            cnthr+=i/rate;
            if(i%rate!=0) cnthr++;
        }
        return cnthr<=hr;
    }

    int minEatingSpeed(vector<int>& piles, int k) {
        int l=1,h=*max_element(piles.begin(),piles.end());

        while(l<=h){
            int m=l+(h-l)/2;

            if(isval(piles,k,m)) h=m-1;
            else l=m+1; 
        }
        return l;
    }
};