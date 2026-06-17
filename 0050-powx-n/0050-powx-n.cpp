class Solution {
public:
    double myPow(double x, int n) {
        double t=1.0;

        long long nn= n;
        if(n<0) nn = -1 * nn;

        while(nn>0){
            if(nn%2==1){
                t=t*x;
                nn--;
            }
            else{
                nn=nn/2;
                x=x*x;
            }
        }
        if(n<0) return (1.0/t);
        return t;
    }
};