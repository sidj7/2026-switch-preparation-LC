class Solution {
public:
    bool isval(vector<int>&w,int d,int c){
        int l=0,t=1;

        for(int i:w){
            if(l+i<=c){
                l=l+i;
            }
            else{
                t++;
                l=i;
            }
        }
        return d>=t;
    }

    int shipWithinDays(vector<int>& w, int d) {
        int l=*max_element(w.begin(),w.end()),h=accumulate(w.begin(),w.end(),0);

        while(l<=h){

            int m=l+(h-l)/2;

            if(isval(w,d,m)){
                h=m-1;
            }
            else l=m+1;
        }
        return l;
    }
};