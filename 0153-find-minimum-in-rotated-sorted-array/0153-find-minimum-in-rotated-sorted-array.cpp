class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int ans=5001;
        int n=nums.size();

        int l=0,h=n-1;

        while(l<=h){
            int m=l+(h-l)/2;

            if(ans>nums[m])ans=nums[m];

            if(nums[l]<=nums[m]){
                ans=min(ans,nums[l]);
                l=m+1;
            }
            else{
                ans=min(ans,nums[m]);
                h=m-1;
            }
        }
        return ans;
    }
};