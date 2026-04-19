class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int maxi=INT_MIN;
        for(int i=0;i<n1;i++){
            int low=i;
            int high=n2-1;
            int ans=0;
            while(low<=high){
                int mid=low+(high-low)/2;

                if(nums2[mid]>=nums1[i]){
                    ans=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            maxi=max(maxi,ans-i);
        }
        return maxi;
    }
};