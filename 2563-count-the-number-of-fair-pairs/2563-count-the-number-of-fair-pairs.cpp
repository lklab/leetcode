class Solution
{
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());

        long long result = 0;

        for (int i = 0; i < n - 1; ++i)
        {
            auto begin = nums.begin() + i + 1;

            auto left = lower_bound(begin, nums.end(), lower - nums[i]);
            if (left == nums.end())
            {
                continue;
            }

            auto right = lower_bound(begin, nums.end(), upper - nums[i]);
            if (right == nums.end() || *right > upper - nums[i])
            {
                --right;
            }

            int rightValue = *right;
            if (nums[i] + rightValue > upper)
            {
                continue;
            }

            while (right < nums.end() - 1 && rightValue == *(right + 1))
            {
                ++right;
            }

            // cout << left - nums.begin() << ", " << right - nums.begin() << endl;

            if (right >= left)
            {
                result += right - left + 1;
            }
        }

        return result;
    }
};
