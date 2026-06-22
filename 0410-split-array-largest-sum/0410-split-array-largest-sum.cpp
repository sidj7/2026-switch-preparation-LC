class Solution {
public:
    bool isval(vector<int>& nums, int k,int m){
        int arrcnt=1,sum=0;
        for(int i:nums){
            if(sum+i<=m) sum+=i;

            else{
                sum=i;
                arrcnt++;
            }

        }
        return arrcnt<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(k==1) return accumulate(nums.begin(),nums.end(),0);
        if(k==n) return *max_element(nums.begin(),nums.end());

        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);

        while(l<=h){
            int m=l+(h-l)/2;
            if(isval(nums,k,m)) h=m-1;
            else l=m+1;
        }
        return l;
    }
};