class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxvol=INT_MIN;
        int l=0;
        int r=height.size()-1;
        int currvol=1;

        while(l<=r){
        currvol=(r-l)*min(height[l],height[r]);
        if(height[l]<=height[r]){
            l++;
        }
        else{
            r--;
        }
        maxvol=max(currvol,maxvol);
        }
        return maxvol;
        
    }
};