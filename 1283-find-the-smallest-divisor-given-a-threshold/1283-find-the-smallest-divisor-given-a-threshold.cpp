class Solution {
public:

    bool isval(vector<int>&nums,int t,int m){
        int sum=0;
        for(int i:nums){
            sum = sum + ceil((double)(i)/(double)(m));
        }
        return sum<=t;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int l=1,h=*max_element(nums.begin(),nums.end());
        while(l<=h){
            int m=l+(h-l)/2;

            if(isval(nums,t,m)){
                h=m-1;
            }
            else l=m+1;
        }
        return l;
    }
};