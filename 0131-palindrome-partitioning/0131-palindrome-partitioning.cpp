class Solution {
public:
    bool ispal(string s , int i , int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void func(int i,string s,vector<string>t,vector<vector<string>>&ans){
        if(i==s.size()){
            ans.push_back(t);
            return;
        }

        for(int j=i;j<s.size();++j){
            if(ispal(s,i,j)){
                t.push_back(s.substr(i,j-i+1));
                func(j+1,s,t,ans);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        func(0,s,{},ans);
        return ans;
    }
};