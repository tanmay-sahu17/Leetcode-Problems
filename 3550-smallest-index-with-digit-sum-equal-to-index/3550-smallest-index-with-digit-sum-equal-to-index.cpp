class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        int sum=0;
        int mini=INT_MAX;

        for(int i=0;i<nums.size();i++){
            int num=nums[i];

            while(num!=0){
                int digit=num%10;
                sum+=digit;
                num/=10;
            }
            if(i==sum){
                mini=min(i,mini);
            }
            sum=0;
        }
       if(mini!=INT_MAX)return mini;
       return -1;
    }
};