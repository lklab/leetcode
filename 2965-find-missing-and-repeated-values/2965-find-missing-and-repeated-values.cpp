class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int n2 = n * n;
        vector<bool> found(n2 + 1, false);
        vector<int> result(2);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int num = grid[i][j];
                if (found[num]) {
                    result[0] = num;
                } else {
                    found[num] = true;
                }
            }
        }

        for (int i = 1; i <= n2; ++i) {
            if (!found[i]) {
                result[1] = i;
                break;
            }
        }

        return result;
    }
};
