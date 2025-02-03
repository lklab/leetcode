class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result = 1;
        int increasing = 1;
        int decreasing = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                result = max(result, decreasing);
                ++increasing;
                decreasing = 1;
            } else if (nums[i - 1] > nums[i]) {
                result = max(result, increasing);
                ++decreasing;
                increasing = 1;
            } else {
                result = max(result, increasing);
                result = max(result, decreasing);
                increasing = 1;
                decreasing = 1;
            }
        }

        result = max(result, increasing);
        result = max(result, decreasing);
        return result;
    }
};
