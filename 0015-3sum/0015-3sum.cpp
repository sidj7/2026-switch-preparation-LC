class Solution {
public:
    vector<vector<int>> threeSum_better(vector<int>& nums) {
        set<vector<int>>st;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            set<int>mp;
            for(int j=i+1;j<n;j++){
                int remain = - (nums[i] + nums[j]);
                if(mp.find(remain)!=mp.end()){
                    if(st.find({nums[i],nums[j],remain})==st.end())
                        st.insert({nums[i],nums[j],remain});
                }
                mp.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }







    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++){

            if(i>0 && nums[i]==nums[i-1]) continue;

            int l=i+1,r=n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++;r--;
                }
                else if(nums[i]+nums[l]+nums[r] > 0){
                    r--;
                }
                else{
                    l++;
                }
            }

        }
        return ans;
    }
};