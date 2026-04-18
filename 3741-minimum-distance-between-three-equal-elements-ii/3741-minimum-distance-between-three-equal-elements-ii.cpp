class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int mini=INT_MAX;
      for(auto &it : mp){
            vector<int> &v=it.second;
            if(v.size()>=3){
                for(int i=0;i+2<v.size();i++){
                mini=min(mini,abs(v[i]-v[i+1])+abs(v[i+1]-v[i+2])+abs(v[i+2]-v[i]));
                }
            }
        }
       return mini==INT_MAX?-1:mini;
    }
};