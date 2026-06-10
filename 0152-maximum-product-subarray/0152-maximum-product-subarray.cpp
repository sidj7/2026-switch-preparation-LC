class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p=1,s=1,mx=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(p==0) p=1;
            if(s==0) s=1;

            p*=nums[i];
            s*=nums[n-i-1];

            mx=max({mx,p,s});
        }
        return mx;
    }
};