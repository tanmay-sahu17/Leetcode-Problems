class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, unordered_set<int>> mp;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row].insert(col);
        }

        int ans = (n - mp.size()) * 2;

        for (auto &it : mp) {

            auto reserved = it.second;

            bool left =
                !reserved.count(2) &&
                !reserved.count(3) &&
                !reserved.count(4) &&
                !reserved.count(5);

            bool middle =
                !reserved.count(4) &&
                !reserved.count(5) &&
                !reserved.count(6) &&
                !reserved.count(7);

            bool right =
                !reserved.count(6) &&
                !reserved.count(7) &&
                !reserved.count(8) &&
                !reserved.count(9);

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};