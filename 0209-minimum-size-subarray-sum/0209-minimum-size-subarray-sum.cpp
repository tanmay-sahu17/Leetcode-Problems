class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int sum=0;
        int n=nums.size();
        int minlen=INT_MAX;

        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(sum>=target){
               
                minlen=min(minlen,right-left+1);
                sum-=nums[left];
                 left++;
            }

        }
       if(minlen!=INT_MAX){
        return minlen;
       }
       return 0;
        
    }
};