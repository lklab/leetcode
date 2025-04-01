class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        long long prefix = 0;
        long long result = 0;

        for (int i = 0; i < n; ++i) {
            prefix = max(prefix, dp[i]);
            dp[i] = prefix + questions[i][0];
            int next = i + questions[i][1] + 1;
            if (next < n) {
                dp[next] = max(dp[next], dp[i]);
            }

            result = max(result, dp[i]);
        }

        return result;
    }
};
