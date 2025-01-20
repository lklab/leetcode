class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> map;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                map[mat[i][j]] = {i, j};
            }
        }

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int i = 0; i < arr.size(); ++i) {
            pair<int, int> pair = map[arr[i]];
            if (++row[pair.first] == n) {
                return i;
            }
            if (++col[pair.second] == m) {
                return i;
            }
        }

        return 0;
    }
};
