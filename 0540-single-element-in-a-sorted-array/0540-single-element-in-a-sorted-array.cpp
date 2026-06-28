class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=1,h=n-2;

        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-2]!=nums[n-1]) return nums[n-1];

        int ans;

        while(l<=h){
            int m=l+(h-l)/2;

            if(nums[m-1]!=nums[m] && nums[m]!=nums[m+1]){
                ans=nums[m];
                break;
            }

            else if((m%2==1 && nums[m-1]==nums[m])||(m%2==0 && nums[m]==nums[m+1])){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return ans;
    }
};