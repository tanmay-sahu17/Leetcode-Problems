class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int srow=0;
        int scol=0;
        vector<int>ans;
        int erow=matrix.size()-1;
        int ecol=matrix[0].size()-1;

        while(srow<=erow&&scol<=ecol){

        for(int j=scol;j<=ecol;j++){
              ans.push_back(matrix[srow][j]);
        }
         for(int i=srow+1;i<=erow;i++){
              ans.push_back(matrix[i][ecol]);
        }
         if (srow < erow) {
                for (int j = ecol - 1; j >= scol; j--) {
                    ans.push_back(matrix[erow][j]);
                }
            }
            if (scol < ecol) {
                for (int i = erow - 1; i > srow; i--) {
                    ans.push_back(matrix[i][scol]);
                }
            }
        srow++;
        erow--;
        scol++;
        ecol--;
        
          }
          return ans;
    }
};