class Solution {
public:
    int mySqrt(int x) {
        int l=0, h=x;

        while(l<=h){
            int mid= l + (h-l)/2;

            long long val= (long long)mid*mid;

            if(val==x) return mid;

            else if(val<x) l=mid+1;

            else h=mid-1;

        }
        return h;
    }
};