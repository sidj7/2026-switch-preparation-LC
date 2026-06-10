class Solution {
public:

    int merge(vector<int>&a, int l,int m,int h){
        int cnt=0;
        int r=m+1;
        int x=l;
        for(int i=l;i<=m;i++){
            while(r<=h && a[i]> (long long)a[r]*2) r++;

            cnt+=(r-(m+1));  
        }
        r=m+1;

        vector<int>t;
        while(l<=m && r<=h){
            if(a[l]<=a[r]) t.push_back(a[l++]);
            else t.push_back(a[r++]);
        }
        while(l<=m) t.push_back(a[l++]);
        while(r<=h) t.push_back(a[r++]);
        for(int i=x;i<=h;i++) a[i]=t[i-x];
        return cnt;
    }
    int msort(vector<int>& a,int l,int h){
        if(l>=h) return 0;

        int cnt=0;

        int m= l+(h-l)/2;

        cnt+=msort(a,l,m);
        cnt+=msort(a,m+1,h);
        cnt+=merge(a,l,m,h);

        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        
        return msort(nums,0,nums.size()-1);
    }
};