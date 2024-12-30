class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1, 0);
        long long result = 0;

        for (int i = 1; i <= high; ++i) {
            if (i == zero) {
                dp[i] += 1;
            } else if (i > zero) {
                dp[i] += dp[i - zero];
            }

            if (i == one) {
                dp[i] += 1;
            } else if (i > one) {
                dp[i] += dp[i - one];
            }

            dp[i] %= 1000000007;

            if (i >= low) {
                result += dp[i];
                result %= 1000000007;
            }
        }

        return result;
    }
};
