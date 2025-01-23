class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowHalf(m, -1);
        vector<int> colHalf(n, -1);
        vector<int> rowFull(m, 0);
        vector<int> colFull(n, 0);
        vector<pair<int, int>> servers;
        int serverIndex = 0;
        int result = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int r = rowHalf[i];
                    int c = colHalf[j];
                        // cout << serverIndex << ": r=" << r << ", c=" << c << endl;

                    // check half
                    if (r != -1 && c != -1) {
                        // cout << serverIndex << ": half3" << endl;
                        result += 3;

                        rowFull[i] = 1;
                        colFull[j] = 1;
                        rowFull[servers[c].first] = 1;
                        colFull[servers[r].second] = 1;

                        rowHalf[i] = -1;
                        colHalf[j] = -1;
                        rowHalf[servers[c].first] = -1;
                        colHalf[servers[r].second] = -1;

                    } else if (r != -1) {
                        // cout << serverIndex << ": half2 row" << endl;
                        result += 2;

                        rowFull[i] = 1;
                        colFull[j] = 1;
                        colFull[servers[r].second] = 1;

                        rowHalf[i] = -1;
                        colHalf[servers[r].second] = -1;

                    } else if (c != -1) {
                        // cout << serverIndex << ": half2 col" << endl;
                        result += 2;

                        rowFull[i] = 1;
                        colFull[j] = 1;
                        rowFull[servers[c].first] = 1;

                        colHalf[j] = -1;
                        rowHalf[servers[c].first] = -1;

                    // check full
                    } else if (rowFull[i] != 0 || colFull[j] != 0) {
                        // cout << serverIndex << ": full" << endl;
                        result += 1;
                        rowFull[i] = 1;
                        colFull[j] = 1;

                    // others
                    } else {
                        // cout << serverIndex << ": others" << endl;
                        rowHalf[i] = serverIndex;
                        colHalf[j] = serverIndex;
                    }

                    servers.emplace_back(i, j);
                    ++serverIndex;
                }
            }
        }

        return result;
    }
};
