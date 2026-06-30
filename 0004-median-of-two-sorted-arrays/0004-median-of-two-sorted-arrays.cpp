class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        int tn=n1+n2;
        int cnt2=tn/2;
        int cnt1=cnt2-1;
        int el1,el2;
        int i=0,j=0;
        int cnt=0;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                if(cnt==cnt1) el1=nums1[i];
                if(cnt==cnt2) el2=nums1[i];
                i++;
            }
            else{
                if(cnt==cnt1) el1=nums2[j];
                if(cnt==cnt2) el2=nums2[j];
                j++;
            }
            cnt++;
        }
        while(i<n1){
            if(cnt==cnt1) el1=nums1[i];
            if(cnt==cnt2) el2=nums1[i];
            i++;cnt++;
        }
        while(j<n2){
            if(cnt==cnt1) el1=nums2[j];
            if(cnt==cnt2) el2=nums2[j];
            j++;cnt++;
        }
        if(tn%2==0){
            return (el1+el2)/2.0;
        }
        return el2;
    }
};