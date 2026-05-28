class Solution {
public:

    void func(int i,int n,vector<int>t,vector<int>&nums,vector<vector<int>>&ans){
        if(i==n){
            ans.push_back(t);
            return;
        }

        t.push_back(nums[i]);
        func(i+1,n,t,nums,ans);
        t.pop_back();
        func(i+1,n,t,nums,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        func(0,n,{},nums,ans);
        return ans;
    }
};