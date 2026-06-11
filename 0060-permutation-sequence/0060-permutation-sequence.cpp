class Solution {
public:
    string getPermutation(int n, int k) {
        //vector<int> arr(n); iota(arr.begin(), arr.end(), 1);  populate arr with 1 to N;

        vector<int>nums;
        k--;
        int fact=1;
        for(int i=1;i<n;i++){
            nums.push_back(i);
            fact*=i;
        }
        nums.push_back(n);
        string ans="";
        while(true){
            ans+=('0'+nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0) break;

            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;

    }
};