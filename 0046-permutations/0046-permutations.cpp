class Solution {
public:

    void func(int i,int n,vector<int>t,vector<vector<int>>&ans,vector<int>nums){
        
        if(t.size()==nums.size()){
            ans.push_back(t);
            return;
        }

        for(int idx=0;idx<n;idx++){
            if(count(t.begin(),t.end(),nums[idx])) continue;
            t.push_back(nums[idx]);
            func(idx,n,t,ans,nums);
            t.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        func(0,n,{},ans,nums);
        return ans;
    }
};