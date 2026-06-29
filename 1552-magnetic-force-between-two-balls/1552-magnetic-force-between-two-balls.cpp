class Solution {
public:

    bool isval(vector<int>&pos,int b,int mf){
        int cnt=1,last=pos[0];
        for(int i=1;i<pos.size();i++){
            if(pos[i]-last>=mf){
                cnt++;
                last=pos[i];
                if(cnt>=b) return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int h=pos.back()-pos[0];
        int l=1;

        while(l<=h){
            int md=l+(h-l)/2;

            if(isval(pos,m,md)){
                l=md+1;
            }
            else h=md-1;
        }
        return h;
    }
};