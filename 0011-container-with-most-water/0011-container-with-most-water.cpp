class Solution {
public:
    int maxArea(vector<int>& height) {
        int r=height.size()-1;
        int l=0;
        int area=0;

        while(l<r){
            int new_area=min(height[l],height[r])*(r-l);
            area=max(area,new_area);

            if(height[l]>height[r]) r--;
            else l++;
        }
        return area;
    }
};