class Solution {
public:
    vector<int> getRow(int row) {
        long long res=1;
        vector<int> ans;
        ans.push_back(1);
        row++;
        for(int col=1;col<row ; col++){
            res=res*(row-col);
            res=res/(col);
            ans.push_back(res);
        }
        return ans;
    }
};