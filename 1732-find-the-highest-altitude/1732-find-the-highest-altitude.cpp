class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int currgain=0;
        for(int i=0;i<gain.size();i++){
            currgain+=gain[i];
            ans=max(ans,currgain);
        }
        return ans;
    }
};