class Solution {
public:
   int solve(vector<vector<int>>& grid,int i,int j,int maxans){
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0){
        return 0;
    }
    int ans=grid[i][j];
    grid[i][j]=0;
    int up=solve(grid,i-1,j,maxans);
    int right=solve(grid,i,j+1,maxans);
     int down=solve(grid,i+1,j,maxans);
    int left=solve(grid,i,j-1,maxans);
     grid[i][j]=ans;

    return ans+max({up,right,down,left});

   }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=INT_MIN;
        int maxans=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!=0){
                ans=solve(grid,i,j,maxans);
                maxans=max(ans,maxans);
            }
        }
       }
        return maxans;
        
    }
};