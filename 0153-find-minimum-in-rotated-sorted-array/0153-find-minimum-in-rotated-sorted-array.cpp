class Solution {
public:
    int findMin(vector<int>& arr) {
        int ans=5001;

        int l=0,h=arr.size()-1;

        while(l<=h){
            int m= l+(h-l)/2;

            if(ans>arr[m])ans=arr[m];

            else if(arr[m]>=arr[l]){
                ans=min(ans,arr[l]);
                l=m+1;
            }

            else h=m-1;


        }
        return ans;
    }
};