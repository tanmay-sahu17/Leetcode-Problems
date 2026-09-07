class Solution {
public:

    void solve(int i, vector<int>& nums, vector<int>& curr,
               set<vector<int>>& st) {

        if (i == nums.size()) {
            st.insert(curr);
            return;
        }

        // Take
        curr.push_back(nums[i]);
        solve(i + 1, nums, curr, st);

        // Backtrack
        curr.pop_back();

        // Not Take
        solve(i + 1, nums, curr, st);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        set<vector<int>> st;
        vector<int> curr;

        solve(0, nums, curr, st);

        vector<vector<int>> ans;

        for (auto x : st) {
            ans.push_back(x);
        }

        return ans;
    }
};