class Solution {
public:

    bool isval(vector<int>&pos,int m,int f){
        int cnt=1,last=pos[0];

        for(int i=1;i<pos.size();i++){
            if(pos[i]-last>=f){
                cnt++;
                last=pos[i];
            }
        }
        return cnt>=m;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int h=pos.back()-pos[0];
        int l=1;
        while(l<=h){

            int mid=l+(h-l)/2;

            if(isval(pos,m,mid)){
                l=mid+1;
            }
            else h=mid-1;
        }
        return h;
    }
};