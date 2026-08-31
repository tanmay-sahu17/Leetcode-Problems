class Solution {
public:
      
      void solve(vector<int>&nums,int index,set<vector<int>>&ans){
        if(index==nums.size()){
            ans.insert(nums);
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,index+1,ans);
            swap(nums[index],nums[i]);
        }
      }
     
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        vector<vector<int>>finalans;
         solve(nums,0,ans);
        for(auto st:ans){
            finalans.push_back(st);
        }
        return finalans;
    }
};