class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int n;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                n=nums[i];
                cnt=1;
            }
            else{
                if(n!=nums[i]) cnt--;
                else cnt++;
            }
        }
        return n;
    }
};