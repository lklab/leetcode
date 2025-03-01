class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int index = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            } else if (i < n - 1 && nums[i] == nums[i + 1]) {
                result[index] = nums[i] * 2;
                ++i;
                ++index;
            } else {
                result[index] = nums[i];
                ++index;
            }
        }

        // result[index] = nums[n - 1];

        return result;
    }
};
