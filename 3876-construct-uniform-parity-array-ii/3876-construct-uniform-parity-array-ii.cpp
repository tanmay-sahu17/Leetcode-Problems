class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
      int minOdd=INT_MAX;

      for(auto x:nums1){
          if(x%2==1){
            minOdd=min(minOdd,x);
          }
      }

      for(auto x:nums1){
        if(x%2==0&&x<minOdd&&minOdd!=INT_MAX){
            return false;
        }
      }
      return true;
    }
};