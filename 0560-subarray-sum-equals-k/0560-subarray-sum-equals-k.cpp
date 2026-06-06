class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int psum=0;
        int cnt=0;
        for(int i:nums){
            psum+=i;
            cnt+=mp[psum-k];
            mp[psum]++;
        }
        return cnt;
    }
};