class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=INT_MIN;
        int currarea=1;

        int i=0;
        int j=height.size()-1;

        while(i<j){
            currarea=min(height[i],height[j])*(j-i);
            maxarea=max(currarea,maxarea);
             if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxarea;
    }
};