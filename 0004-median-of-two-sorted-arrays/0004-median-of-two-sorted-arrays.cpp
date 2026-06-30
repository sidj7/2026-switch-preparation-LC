class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);

        int tn=n1+n2;
        int part=(tn+1)/2;

        int l=0,h=n1;
        double ans;
        while(l<=h){
            int m1=l+(h-l)/2;
            int m2=part-m1;

            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;

            if(m1>0) l1=nums1[m1-1];
            if(m2>0) l2=nums2[m2-1];
            if(m1<n1) r1=nums1[m1];
            if(m2<n2) r2=nums2[m2];

            if(l1<=r2 && l2<=r1){
                if(tn%2==0){
                    ans=(max(l1,l2)+min(r1,r2))/2.0;
                }
                else ans= max(l1,l2);
                break;
            }
            else if(l1>r2) h=m1-1;
            else l=m1+1;
        }
        return ans;
    }
};