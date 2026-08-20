class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int, int> mp;

        int left = 0;
        int right = k - 1;
        int n = nums.size();

        while (right < n) {
            set<int> st;

            for (int i = left; i <= right; i++) {
                st.insert(nums[i]);
            }

            for (auto i : st) {
                mp[i]++;
            }

            left++;
            right++;
        }

        int ans = -1;

        for (auto i : mp) {
            if (i.second == 1) {
                ans = max(ans, i.first);
            }
        }

        return ans;
    }
};