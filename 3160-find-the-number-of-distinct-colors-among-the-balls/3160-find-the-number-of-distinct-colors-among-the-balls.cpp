class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> balls;
        unordered_map<int, int> colors;
        int colorCount = 0;
        vector<int> result(queries.size());

        for (int i = 0; i < queries.size(); ++i) {
            int ball = queries[i][0];
            int color = queries[i][1];
            int beforeColor = balls[ball];

            if (beforeColor != 0) {
                int c = colors[beforeColor] - 1;
                colors[beforeColor] = c;
                if (c == 0) {
                    --colorCount;
                }
            }

            int newCount = colors[color] + 1;
            colors[color] = newCount;
            if (newCount == 1) {
                ++colorCount;
            }

            balls[ball] = color;
            result[i] = colorCount;
        }

        return result;
    }
};
