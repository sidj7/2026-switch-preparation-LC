class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        int l=1,h=n-2;
        int ans;
        while(l<=h){
            int m=l+(h-l)/2;

            if(nums[m-1]<nums[m] && nums[m+1]<nums[m]){
                ans=m;
                break;
            }
            else if(nums[m-1]>nums[m] && nums[m+1]<nums[m]){
                l--;
                continue;
            }
            else if(nums[m-1]<nums[m]){
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
    }
};