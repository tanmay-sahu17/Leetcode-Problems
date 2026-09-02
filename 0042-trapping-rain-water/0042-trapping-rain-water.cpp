class Solution {
public:
    int trap(vector<int>& heights) {
          int n=heights.size();
        vector<int>left(n);
        vector<int>right(n);
        int ans=0;
      
        left[0]=heights[0];
        right[n-1]=heights[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(heights[i],left[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(heights[i],right[i+1]);
        }

        for(int i=0;i<n;i++){
         ans+=min(left[i],right[i])-heights[i];
        }
        return ans;
    }
};