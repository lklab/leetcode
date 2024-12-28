class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0); // Prefix sum
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }

        // Left and Right DP arrays
        vector<int> left(n, 0), right(n, n - k);

        // Fill left DP array
        int max_sum = sum[k] - sum[0];
        for (int i = k; i < n; ++i) {
            if (sum[i + 1] - sum[i + 1 - k] > max_sum) {
                max_sum = sum[i + 1] - sum[i + 1 - k];
                left[i] = i + 1 - k;
            } else {
                left[i] = left[i - 1];
            }
        }

        // Fill right DP array
        max_sum = sum[n] - sum[n - k];
        for (int i = n - k - 1; i >= 0; --i) {
            if (sum[i + k] - sum[i] >= max_sum) {
                max_sum = sum[i + k] - sum[i];
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }

        // Find the result
        vector<int> result(3, -1);
        max_sum = 0;
        for (int i = k; i <= n - 2 * k; ++i) {
            int l = left[i - 1], r = right[i + k];
            int total = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
            if (total > max_sum) {
                max_sum = total;
                result = {l, i, r};
            }
        }

        return result;
    }
};