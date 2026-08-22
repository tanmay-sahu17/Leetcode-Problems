class Solution {
public:
    bool checkDivisibility(int n) {
        int digitsum=0;
        int productsum=1;

        int temp1=n;
        while(temp1!=0){
            int digit=temp1%10;
            digitsum+=digit;
            temp1/=10;
        }
        int temp2=n;
        while(temp2!=0){
            int digit=temp2%10;
            productsum*=digit;
            temp2/=10;
        }
        if(n%(digitsum+productsum)==0){
            return true;
        }
        return false;
    }
};