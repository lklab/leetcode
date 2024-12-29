class Solution {
private:
    int n;
    int k;

    int find(vector<vector<int>>& freq, string& target, vector<vector<int>>& dp, int i, int t) {
        if (t == k) {
            return 1;
        }

        long long result = 0;

        for (; i <= n - k + t; ++i) {
            long long current = 0;

            if (dp[i][t] != -1) {
                current = dp[i][t];
            } else {
                current = freq[i][target[t] - 'a'];
                current *= find(freq, target, dp, i + 1, t + 1);
                current %= 1000000007;
                dp[i][t] = current;
            }

            result += current;
            result %= 1000000007;
        }

        return result;
    }

public:
    int numWays(vector<string>& words, string target) {
        n = words[0].size();
        k = target.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        vector<vector<int>> dp(n, vector<int>(k, -1));

        for (const auto& word : words) {
            for (int i = 0; i < n; ++i) {
                ++freq[i][word[i] - 'a'];
            }
        }

        int result = find(freq, target, dp, 0, 0);

        return result;
    }
};
