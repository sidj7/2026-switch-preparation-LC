class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans=-1;
        int n=arr.size();
        int l=0,h=n-1;

        while(l<h){
            int m=l+(h-l)/2;

            if(arr[m]>arr[m-1] && arr[m]>arr[m+1]){
                ans=m; break;
            }

            if(arr[m]>=arr[m-1]) l=m;

            else h=m;
        }
        return ans;

    }
};