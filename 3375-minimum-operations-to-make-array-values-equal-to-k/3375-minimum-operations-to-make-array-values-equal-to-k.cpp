class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool> exists(101, false);
        int result = 0;

        for (int num : nums) {
            if (num < k) {
                return -1;
            } else if (num > k) {
                if (!exists[num]) {
                    ++result;
                    exists[num] = true;
                }
            }
        }

        return result;
    }
};
