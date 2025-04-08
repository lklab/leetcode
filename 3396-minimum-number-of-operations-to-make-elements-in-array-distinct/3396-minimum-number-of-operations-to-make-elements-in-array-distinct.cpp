class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> counter(101, 0);
        int duplicateds = 0;

        for (int num : nums) {
            if (++counter[num] == 2) {
                ++duplicateds;
            }
        }

        int result = 0;
        int index = 0;
        while (duplicateds > 0 && index < n) {
            for (int i = index; i < index + 3 && i < n; ++i) {
                if (--counter[nums[i]] == 1) {
                    --duplicateds;
                }
            }

            ++result;
            index += 3;
        }

        return result;
    }
};
