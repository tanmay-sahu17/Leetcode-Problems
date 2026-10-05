class Solution {
public:

    int manDist(vector<vector<int>>& points, int i, int j) {
        return abs(points[i][0] - points[j][0]) +
               abs(points[i][1] - points[j][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // {cost, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<bool> mstSet(n, false);

        int mstCost = 0;

        // Start from node 0
        pq.push({0, 0});

        while (!pq.empty()) {

            int wt = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            // Already added in MST
            if (mstSet[node])
                continue;

            // Add node to MST
            mstSet[node] = true;
            mstCost += wt;

            // Connect this node with all unvisited nodes
            for (int i = 0; i < n; i++) {

                if (!mstSet[i]) {

                    int cost = manDist(points, node, i);

                    pq.push({cost, i});
                }
            }
        }

        return mstCost;
    }
};