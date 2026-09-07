class Solution {
public:

    void solve(int i, vector<int>& candidates, int target,
               vector<int>& curr, vector<vector<int>>& ans) {

        // Target mil gaya
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        // Target negative ho gaya
        if (target < 0 || i >= candidates.size()) {
            return;
        }

        // Take
        curr.push_back(candidates[i]);

        // i hi rahega because same element dobara le sakte hain
        solve(i, candidates, target - candidates[i], curr, ans);

        // Backtrack
        curr.pop_back();

        // Not Take
        solve(i + 1, candidates, target, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, candidates, target, curr, ans);

        return ans;
    }
};