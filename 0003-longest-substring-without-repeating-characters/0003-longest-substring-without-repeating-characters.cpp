class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0,r=0;
        int n=s.size();
        int ans=0;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            r++;
            ans=max(ans,r-l);
        }
        return ans;
    }
};