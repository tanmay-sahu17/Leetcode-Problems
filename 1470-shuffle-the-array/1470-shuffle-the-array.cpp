class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int j=n;
        vector<int>ans;
        int turn=0;
        int i=0;

        for(int k=0;k<2*n;k++){
           if(turn==0){
            ans.push_back(nums[i]);
            i++;
            turn=1;
           }
           else{
            ans.push_back(nums[j]);
            turn=0;
            j++;
           }
        }
        return ans;
    }
};