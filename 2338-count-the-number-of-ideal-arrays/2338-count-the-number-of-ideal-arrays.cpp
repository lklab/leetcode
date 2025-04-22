class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int MOD = 1e9 + 7;
        const int maxLen = 14;  // log2(10^4) < 14

        // 조합 계산: comb[i][j] = C(i, j)
        vector<vector<int>> comb(n + 1, vector<int>(maxLen + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= maxLen && j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        // dp[len][val]: 길이 len, 마지막 값이 val인 배열 수
        vector<vector<int>> dp(maxLen + 1, vector<int>(maxValue + 1, 0));
        for (int i = 1; i <= maxValue; ++i) {
            dp[1][i] = 1;
        }

        for (int len = 2; len <= maxLen; ++len) {
            for (int val = 1; val <= maxValue; ++val) {
                for (int mul = 2; val * mul <= maxValue; ++mul) {
                    int next = val * mul;
                    dp[len][next] = (dp[len][next] + dp[len - 1][val]) % MOD;
                }
            }
        }

        // 결과 계산
        long long res = 0;
        for (int len = 1; len <= maxLen; ++len) {
            for (int val = 1; val <= maxValue; ++val) {
                res = (res + 1LL * dp[len][val] * comb[n - 1][len - 1]) % MOD;
            }
        }

        return res;
    }
};
