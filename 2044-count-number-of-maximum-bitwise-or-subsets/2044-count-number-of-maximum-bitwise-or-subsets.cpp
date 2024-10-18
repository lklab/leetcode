// source: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/solutions/5928761/beats-96-00-step-by-step-breakdown/?envType=daily-question&envId=2024-10-18

class Solution
{
private:
    int pows[16] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };

public:
    void backtrack(const vector<int> &nums, int index, int currentOR, int maxOR, int &count)
    {
        if (currentOR == maxOR)
        {
            count += pows[nums.size() - index];
            return;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            backtrack(nums, i + 1, currentOR | nums[i], maxOR, count);
        }
    }

    int countMaxOrSubsets(vector<int>& nums)
    {
        int maxOR = 0;

        // Step 1: Compute the maximum OR
        for (int num : nums)
        {
            maxOR |= num;
        }

        int count = 0;
        // Step 2: Backtrack to count the subsets
        backtrack(nums, 0, 0, maxOR, count);

        return count;
    }
};
