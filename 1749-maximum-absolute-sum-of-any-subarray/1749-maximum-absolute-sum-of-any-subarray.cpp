class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        // find max
        int before = 0;
        int maxSum = 0;
        for (int i = 0; i < n; ++i) {
            before = max(nums[i], nums[i] + before);
            maxSum = max(maxSum, before);
        }

        // find min
        before = 0;
        int minSum = 0;
        for (int i = 0; i < n; ++i) {
            before = min(nums[i], nums[i] + before);
            minSum = min(minSum, before);
        }

        return max(maxSum, -minSum);
    }
};
