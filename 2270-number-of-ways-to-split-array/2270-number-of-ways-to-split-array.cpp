class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long lSum = 0;
        long long rSum = 0;
        int result = 0;

        for (int num : nums) {
            rSum += num;
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            lSum += nums[i];
            rSum -= nums[i];

            if (lSum >= rSum) {
                ++result;
            }
        }

        return result;
    }
};
