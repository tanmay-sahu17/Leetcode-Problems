class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int si, sj;
        vector<pair<int, int>> litter;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    si = i;
                    sj = j;
                }

                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // Har litter ko id do
        vector<vector<int>> id(n, vector<int>(m, -1));

        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        int totalMask = 1 << k;

        // visited[i][j][mask] = maximum energy
        // jiske saath hum is state tak pahunch chuke hain
        vector<vector<vector<int>>> visited(
            n,
            vector<vector<int>>(m, vector<int>(totalMask, -1))
        );

        // i, j, energy, mask
        queue<array<int, 4>> q;

        q.push({si, sj, energy, 0});

        visited[si][sj][0] = energy;

        int moves = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [i, j, currEnergy, mask] = q.front();
                q.pop();

                if (mask == totalMask - 1) {
                    return moves;
                }

                for (int d = 0; d < 4; d++) {

                    int ni = i + dr[d];
                    int nj = j + dc[d];

                    if (ni < 0 || ni >= n ||
                        nj < 0 || nj >= m)
                        continue;

                    if (classroom[ni][nj] == 'X')
                        continue;

                    if (currEnergy == 0)
                        continue;

                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    // Litter collect
                    if (classroom[ni][nj] == 'L') {
                        int idx = id[ni][nj];
                        newMask |= (1 << idx);
                    }

                    // Recharge
                    if (classroom[ni][nj] == 'R') {
                        newEnergy = energy;
                    }

                    /*
                        Agar same state me pehle hi
                        equal ya zyada energy ke saath
                        pahunch chuke hain, toh dobara
                        jaana useless hai.
                    */
                    if (visited[ni][nj][newMask] >= newEnergy)
                        continue;

                    visited[ni][nj][newMask] = newEnergy;

                    q.push({
                        ni,
                        nj,
                        newEnergy,
                        newMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};