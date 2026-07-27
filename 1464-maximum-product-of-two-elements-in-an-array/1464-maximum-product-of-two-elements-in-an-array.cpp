class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxele=-1;
        int maxele2=-1;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]>maxele){
                maxele2=maxele;
                maxele=nums[i];
            }
             else if (nums[i] > maxele2) {   
                maxele2 = nums[i];
            }
        }
        return (maxele-1)*(maxele2-1);
        
    }
};