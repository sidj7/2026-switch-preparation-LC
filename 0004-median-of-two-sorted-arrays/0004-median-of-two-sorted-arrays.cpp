class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;
        int tn=n1+n2;
        int id1=(tn/2)-1;
        int id2=tn/2;
        int e1=-1,e2=-1;
        int cnt=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==id1) e1=nums1[i];
                if(cnt==id2) e2=nums1[i];
                i++;
            }
            else{
                if(cnt==id1) e1=nums2[j];
                if(cnt==id2) e2=nums2[j];
                j++;
            }
            cnt++;
        }
        while(i<n1){
            if(cnt==id1) e1=nums1[i];
            if(cnt==id2) e2=nums1[i];
            i++;
            cnt++;
        }
        while(j<n2){
            if(cnt==id1) e1=nums2[j];
            if(cnt==id2) e2=nums2[j];
            j++;
            cnt++;
        }

        if(tn%2==1) return e2;
        return (e1+e2)/2.0;
    }
};