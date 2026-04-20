class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int maxdistance=INT_MIN;
        for(int i=0;i<n;i++){
            int color=colors[i];
            for(int j=0;j<n;j++){
                if(colors[j]!=color){
                 maxdistance=max(maxdistance,abs(i-j));
                }
            }
        }
        return maxdistance;
        
    }
};