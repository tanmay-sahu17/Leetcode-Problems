class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<pair<int,int>>ans;
        vector<int>finalans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            ans.push_back({i.second,i.first});
        }
        sort(ans.rbegin(),ans.rend());
        
        for(int i=0;i<k;i++){
           finalans.push_back(ans[i].second);
        }
        return finalans;
    }
};