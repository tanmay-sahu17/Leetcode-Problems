class Solution {
public:
   int rev(int n){
    int rev=0;
    while(n!=0){
        int digit=n%10;
        rev=rev*10+digit;
        n/=10;
    }
    return rev;
   }
    int mirrorDistance(int n) {
        int reverse1=rev(n);
        int ans=abs(n-reverse1);
        return ans;
        
    }
};