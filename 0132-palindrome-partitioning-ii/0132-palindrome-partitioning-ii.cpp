
class Solution {
public:
    bool isPal(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s,int i,vector<int>&dp){
        if(i==s.size())return 0;

        if(dp[i]!=-1)return dp[i];

        int mini=INT_MAX;

        for(int j=i;j<s.size();j++){
            if(isPal(s,i,j)){
                mini=min(mini,1+solve(s,j+1,dp));
            }
        }

        return dp[i]=mini;
    }

    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return solve(s,0,dp)-1;
    }
};
