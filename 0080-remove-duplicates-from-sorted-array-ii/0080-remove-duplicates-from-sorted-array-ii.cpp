class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        unordered_map<int, int> mp;

        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(mp[nums[i]] < 2) {
                nums[j] = nums[i];
                j++;
                mp[nums[i]]++;
            }
        }

        return j;
    }
};