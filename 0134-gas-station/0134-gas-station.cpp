class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int currgas = 0;
        int totalgas = 0;

        int n = gas.size();

        for (int i = 0; i < n; i++) {
            currgas += gas[i] - cost[i];
            totalgas += gas[i] - cost[i];

            if (currgas < 0) {
                start = i + 1;
                currgas = 0;
            }
        }

        if (totalgas < 0) {
            return -1;
        }

        return start;
    }
};