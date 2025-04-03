class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_max(n);
        vector<int> suffix_max(n);

        prefix_max[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix_max[i] = max(nums[i], prefix_max[i - 1]);
        }

        suffix_max[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_max[i] = max(nums[i], suffix_max[i + 1]);
        }

        long long result = 0;
        for (int i = 1; i < n - 1; ++i) {
            result = max(result, (long long)(prefix_max[i - 1] - nums[i]) * suffix_max[i + 1]);
        }

        return result;
    }
};
