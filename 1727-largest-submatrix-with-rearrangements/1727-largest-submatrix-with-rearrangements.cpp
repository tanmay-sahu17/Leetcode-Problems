class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>>heights=matrix;

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(heights[i][j]==1){
                    heights[i][j]+=heights[i-1][j];
                }
            }
        }
            int ans=0;
            for(int i=0;i<m;i++){
            vector<int> row = heights[i];
            sort(row.begin(), row.end(), greater<int>());

            for(int j=0;j<n;j++){
                ans = max(ans, row[j]*(j+1));
            }
        }

        return ans;
    }
};