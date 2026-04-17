class Solution {
public:
    int rev(int x) {
        int ans = 0;
        while (x > 0) {
            ans = ans * 10 + (x % 10);
            x /= 10;
        }
        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int dist = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int R = rev(x);

            if (mp.find(x) != mp.end()) {
                dist = min(dist, i - mp[x]);
            }

            mp[R] = i;
        }

        return dist == INT_MAX ? -1 : dist;
    }
};