class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1,el2;
        int cnt1=0,cnt2=0;
        int k=(nums.size())/3;
        vector<int>ans;
        for(int i:nums){
            if(cnt1==0 && i!=el2){
                el1=i;
                cnt1++;
            }
            else if(cnt2==0 && i!=el1){
                el2=i;
                cnt2++;
            }
            else if(i==el1) cnt1++;
            else if(i==el2) cnt2++;

            else {
                cnt1--;
                cnt2--;
            }
       }
       cnt1=0,cnt2=0;
       for(int i:nums){
        if(i==el1) cnt1++;
        if(i==el2) cnt2++;
       }
       if(cnt1>k && cnt2>k){
        return {el1,el2};
       }
       else if(cnt1>k){
        return {el1};
       }
       else if(cnt2>k){
        return {el2};
       }
       return{};
    }
};