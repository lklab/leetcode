class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr(n * m);

        int base = grid[0][0];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((grid[i][j] - base) % x != 0) {
                    return -1;
                }

                arr[i * m + j] = grid[i][j];
            }
        }

        if (arr.size() == 1) {
            return 0;
        }

        sort(arr.begin(), arr.end());

        int minVal = arr[0];
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] -= minVal;
            arr[i] /= x;
        }

        x = arr[n / 2];
        int result1 = 0;
        for (int i : arr) {
            result1 += abs(i - x);
        }

        x = arr[n / 2 - 1];
        int result2 = 0;
        for (int i : arr) {
            result2 += abs(i - x);
        }

        return min(result1, result2);
    }
};
