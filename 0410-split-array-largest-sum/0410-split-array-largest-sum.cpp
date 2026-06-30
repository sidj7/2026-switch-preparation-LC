class Solution {
public:

    bool isval(vector<int>&nums,int k,int m){
        int sum=0;
        int cnt=1;
        for(int i:nums){
            if(i>m) return false;

            if(sum+i<=m){
                sum+=i;
            }
            else{
                sum=i;
                cnt++;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);

        int n=nums.size();
        if(n==1) return nums[0];
        if(k==1) return h;
        if(n==k) return l;

        while(l<=h){

            int m=l+(h-l)/2;

            if(isval(nums,k,m)){
                h=m-1;
            }
            else l=m+1;

        }
        return l;
    }
};