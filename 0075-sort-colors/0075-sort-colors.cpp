class Solution {
public:
    void sortColors(vector<int>& arr) {
        int high=arr.size()-1;
        int low =0, mid=0;

        while(mid<=high){

            if(arr[mid]==0){
                swap(arr[mid++],arr[low++]);
            }
            else if(arr[mid]==1) mid++;

            else swap(arr[mid],arr[high--]);
        }
    }
};