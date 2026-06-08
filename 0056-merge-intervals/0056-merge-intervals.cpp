class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        for(vector<int> i:arr){
            if(ans.empty() || ans.back()[1]<i[0]) ans.push_back(i);
            else ans.back()[1]=max(ans.back()[1],i[1]);
        }
        return ans;
    }
};