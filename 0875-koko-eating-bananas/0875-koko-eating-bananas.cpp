class Solution {
public:
    int func(vector<int>&arr,int rate,int limit){
        long ans = 0;
        for (int i : arr) {
            // Integer math trick for ceiling: (A + B - 1) / B
            // Using 1LL forces the calculation to be evaluated as a long long
            ans+=i/rate;
            if(i%rate!=0) ans++;
        }
        return ans<=limit;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=1e9+1;
        int high=*max_element(piles.begin(),piles.end()),low=1;
        while(low<=high){

            int m= low+(high-low)/2;


            if(func(piles,m,h)){
                ans=min(ans,m);
                high=m-1;
            }
            else low=m+1;
        }
        return ans;
    }
};