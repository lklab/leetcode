class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool rotated = false;

        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                if (rotated) {
                    return false;
                } else {
                    rotated = true;
                }
            }
        }

        if (rotated) {
            return nums[0] >= nums[n - 1];
        } else {
            return true;
        }
    }
};
