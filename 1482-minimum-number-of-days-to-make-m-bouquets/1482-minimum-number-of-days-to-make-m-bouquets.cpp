class Solution {
public:

    bool isval(vector<int>&b,int m,int k,int md){
        int bq=0,f=0;
        for(int i:b){
            if(i<=md){
                f++;
            }
            else{
                bq+=(f/k);
                f=0;
            }
        }
        bq+=(f/k);
        return bq>=m;
    }

    int minDays(vector<int>& b, int m, int k) {
        int n=b.size();

        if(n<(long long)m*k) return -1;
        int l=*min_element(b.begin(),b.end());
        int h=*max_element(b.begin(),b.end());


        while(l<=h){
            int md=l+(h-l)/2;
            
            if(isval(b,m,k,md)){
                h=md-1;
            }
            else l=md+1;
        }
        return l;       

    }
};