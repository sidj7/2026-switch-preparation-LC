class Solution {
public:
    string checkpal(string s,int l,int r,int n){
        while(l>=0 && r<n && (l==r || s[l]==s[r])){l--;r++;}
        return s.substr(l+1,r-l-1);
    }

    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        int maxi=0;
        string ans;
        for(int i=0;i<n;i++){
            string a=checkpal(s,i,i,n);
            string b=checkpal(s,i,i+1,n);
            if(maxi <a.size()){
                maxi=a.size();
                ans=a;
            }
            if(maxi <b.size()){
                maxi=b.size();
                ans=b;
            }
        }
        return ans;
    }
};