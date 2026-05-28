class Solution {
public:

    void func(int i,int n,vector<int>t,vector<int>&nums,vector<vector<int>>&ans){

        ans.push_back(t);

        for(int idx=i;idx<n;idx++){

            if(idx!=i && nums[idx]==nums[idx-1]) continue;

            t.push_back(nums[idx]);
            func(idx+1,n,t,nums,ans);
            t.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        func(0,n,{},nums,ans);
        return ans;
    }
};