class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        if(mp[n-1]!=2)return false;
      for(int i=1;i<n-1;i++){
        if(mp[i]!=1)return false;
      }
      return true;
    }   
};