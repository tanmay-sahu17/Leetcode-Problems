class Solution {
public:
    bool iscycle(int node, int numCourses, vector<vector<int>>& adj,
                 vector<bool>& vis, vector<bool>& currpath) {

        vis[node] = true;
        currpath[node] = true;

        for(auto v : adj[node]) {

            if(!vis[v]) {
                if(iscycle(v, numCourses, adj, vis, currpath)) {
                    return true;
                }
            }
            else if(currpath[v]) {
                return true;
            }
        }

        currpath[node] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // Create adjacency list
        for(auto edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];

            adj[u].push_back(v);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> currpath(numCourses, false);

        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {
                if(iscycle(i, numCourses, adj, vis, currpath)) {
                    return false;
                }
            }
        }

        return true;
    }
};