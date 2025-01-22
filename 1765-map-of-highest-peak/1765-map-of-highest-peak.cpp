class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    q.emplace(i, j);
                    isWater[i][j] = 0;
                } else {
                    isWater[i][j] = -1;
                }
            }
        }

        int dirs[] = { -1, 0, 1, 0, -1 };

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            int height = isWater[i][j] + 1;

            for (int d = 0; d < 4; ++d) {
                int i2 = i + dirs[d];
                int j2 = j + dirs[d + 1];

                if (i2 >= 0 && j2 >= 0 && i2 < m && j2 < n && isWater[i2][j2] == -1) {
                    isWater[i2][j2] = height;
                    q.emplace(i2, j2);
                }
            }
        }

        return isWater;
    }
};
