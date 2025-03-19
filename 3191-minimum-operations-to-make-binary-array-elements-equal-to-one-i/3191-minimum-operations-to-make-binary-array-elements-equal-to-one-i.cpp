class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] == 0) {
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
                ++count;
            }
        }

        return nums[n - 1] == 1 && nums[n - 2] == 1 ? count : -1;
    }
};
