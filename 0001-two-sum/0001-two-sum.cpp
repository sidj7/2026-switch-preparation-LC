class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            if(mpp.find(t-nums[i])!=mpp.end()){
                return {mpp[t-nums[i]],i};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};