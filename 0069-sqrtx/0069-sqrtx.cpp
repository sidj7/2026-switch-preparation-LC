class Solution {
public:
    int mySqrt(int x) {
        if(x==1 || x==0) return x;

        int l=1,h=x/2;
        while(l<=h){
            int m=l+(h-l)/2;
            if((long long)m*m<=x){
                l=m+1;
            }
            else h=m-1;
        }
        return h;
    }
};