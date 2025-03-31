class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> costs(n - 1, 0);

        for (int i = 0; i < n - 1; ++i) {
            costs[i] = weights[i] + weights[i + 1];
        }
        sort(costs.begin(), costs.end());

        long long diff = 0;
        for (int i = 0; i < k - 1; ++i) {
            diff += weights[n - 2 - i];
        }
        for (int i = 0; i < k - 1; ++i) {
            diff -= weights[i];
        }

        return diff;
    }
};
