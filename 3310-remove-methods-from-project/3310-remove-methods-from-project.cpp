class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> dir(n), und(n);

        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            dir[u].push_back(v);
            und[u].push_back(v);
            und[v].push_back(u);
        }

        vector<bool> suspicious(n, false);

        auto dfs = [&](auto &&dfs, int u) -> void {
            suspicious[u] = true;
            for (int v : dir[u]) {
                if (!suspicious[v])
                    dfs(dfs, v);
            }
        };

        dfs(dfs, k);

        vector<bool> vis(n, false);

        auto dfs2 = [&](auto &&dfs2, int u) -> void {
            vis[u] = true;
            for (int v : und[u]) {
                if (!vis[v]) {
                    suspicious[v] = false;
                    dfs2(dfs2, v);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!suspicious[i] && !vis[i])
                dfs2(dfs2, i);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};