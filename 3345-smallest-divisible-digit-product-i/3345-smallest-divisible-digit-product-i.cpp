class Solution {
public:
    int smallestNumber(int n, int t) {

        while (1) {
            int temp = n;
            int product = 1;

            while (temp != 0) {
                int num = temp % 10;
                product *= num;
                temp /= 10;
            }

            if (product % t == 0) {
                return n;
            }

            n++;
        }
    }
};