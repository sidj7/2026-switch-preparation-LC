class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int lcs=0, cnt=0, ls=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i:nums){

            if(i-1==ls){
                cnt++;
                ls=i;
            }
            else if(i != ls){
                ls=i;
                cnt=1;
            }

            lcs=max(lcs,cnt);
        }
        return lcs;
    }
};