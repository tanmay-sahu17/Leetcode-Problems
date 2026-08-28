class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
         int remainder=target-nums[i];

        if(mp.find(remainder)!=mp.end()){
            return {i,mp[remainder]};
        }
        mp[nums[i]]=i;
        }
        return {};
    }
};