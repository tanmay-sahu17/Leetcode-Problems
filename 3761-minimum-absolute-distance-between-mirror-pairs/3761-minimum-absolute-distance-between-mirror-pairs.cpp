class Solution {
public:
    int rev(int num) {
        int rev=0;
        while (num!=0) {
            rev=rev*10+(num%10);
            num/=10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mini=INT_MAX;
        for (int i=0;i<nums.size();i++) {
            int num = nums[i];
            int reverse = rev(num);

            if (mp.find(num) != mp.end()) {
                mini=min(mini,i-mp[num]);
            }

            mp[reverse]=i;
        }

        return mini==INT_MAX?-1:mini;
    }
};