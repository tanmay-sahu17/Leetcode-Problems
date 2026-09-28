class Solution {
public:
    int solve(int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size()-1)return 0;
        if(dp[idx]!=-1)return dp[idx];

        int mini=INT_MAX;

        for(int i=1;i<=nums[idx];i++){
            int ans=solve(idx+i,nums,dp);
            if(ans!=INT_MAX){
                mini=min(mini,1+ans);
            }
        }

        return dp[idx]=mini;
    }

    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};