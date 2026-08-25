class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(auto i:nums){
            mp[i]++;
        }
        for(int i=k;;i+=k){
                if(mp.find(i)==mp.end()){
                      return i;
                }
        }
        return -1;
    }
};