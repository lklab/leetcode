class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int ors = 0;
        int result = 0;

        for (int r = 0; r < n; ++r) {
            // cout << l << ", " << r << ", " << ors << ", " << (ors & nums[r]) << endl;
            while ((ors & nums[r]) != 0) {
                ors ^= nums[l];
                ++l;
                // cout << l << ", " << r << ", " << ors << ", " << (ors & nums[r]) << endl;
            }
            ors |= nums[r];

            result = max(result, r - l + 1);
        }

        return result;
    }
};
