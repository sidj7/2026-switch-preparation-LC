class Solution {
public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int n1=nums1.size(),n2=nums2.size();
    //     int i=0,j=0;
    //     int tn=n1+n2;
    //     int id1=(tn/2)-1;
    //     int id2=tn/2;
    //     int e1=-1,e2=-1;
    //     int cnt=0;
    //     while(i<n1 && j<n2){
    //         if(nums1[i]<nums2[j]){
    //             if(cnt==id1) e1=nums1[i];
    //             if(cnt==id2) e2=nums1[i];
    //             i++;
    //         }
    //         else{
    //             if(cnt==id1) e1=nums2[j];
    //             if(cnt==id2) e2=nums2[j];
    //             j++;
    //         }
    //         cnt++;
    //     }
    //     while(i<n1){
    //         if(cnt==id1) e1=nums1[i];
    //         if(cnt==id2) e2=nums1[i];
    //         i++;
    //         cnt++;
    //     }
    //     while(j<n2){
    //         if(cnt==id1) e1=nums2[j];
    //         if(cnt==id2) e2=nums2[j];
    //         j++;
    //         cnt++;
    //     }

    //     if(tn%2==1) return e2;
    //     return (e1+e2)/2.0;
    // }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int tn=n1+n2;
        int lp=(n1+n2+1)/2;

        int l=0, h=n1;
        double ans=0;
        while(l<=h){
            int m1=(l+h)/2;
            int m2=lp-m1;

            int l1=-1e7,l2=-1e7,r1=1e7,r2=1e7;
            if(m1>0) l1=nums1[m1-1];
            if(m2>0) l2=nums2[m2-1];
            if(m1<n1) r1=nums1[m1];
            if(m2<n2) r2=nums2[m2];

            if(l1<=r2 && l2<=r1){
                if(tn%2==1){
                    ans=max(l1,l2);
                }
                else ans=(max(l1,l2)+min(r1,r2))/2.0;
                break;
            }
            else if(l1>r2) h=m1-1;
            else l=m1+1;
        }
        return ans;
    }
};