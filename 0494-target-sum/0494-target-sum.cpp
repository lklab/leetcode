class Solution {
private:
    int find(vector<int>& nums, vector<int>& postSums, int index, int preSum, int target) {
        if (index == nums.size()) {
            return preSum == target ? 1 : 0;
        }

        if (abs(target - preSum) > postSums[index]) {
            return 0;
        }

        return find(nums, postSums, index + 1, preSum + nums[index], target) +
            find(nums, postSums, index + 1, preSum - nums[index], target);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> postSums(n, 0);
        postSums[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            postSums[i] = nums[i] + postSums[i + 1];
        }

        return find(nums, postSums, 0, 0, target);
    }
};