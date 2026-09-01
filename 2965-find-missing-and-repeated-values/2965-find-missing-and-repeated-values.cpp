class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       
        int n=grid[0].size();
        int lastele=n*n;
        vector<int>freq(lastele+1,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freq[grid[i][j]]++;
            }
        }

        int missing=-1;
        int repeated=-1;

        for(int i=0;i<=lastele;i++){
            if(freq[i]==0)missing=i;
            else if (freq[i]==2)repeated=i;
        }
        return {repeated,missing};

    }
};