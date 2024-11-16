class Solution
{
public:
    vector<int> resultsArray(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> result;
        int index = 0;
        int count = 0;

        for (; index < k - 1; ++index)
        {
            if (nums[index + 1] - nums[index] == 1)
            {
                ++count;
            }
        }

        for (; index < n - 1; ++index)
        {
            if (count == k - 1)
            {
                result.push_back(nums[index]);
            }
            else
            {
                result.push_back(-1);
            }

            if (nums[index + 1] - nums[index] == 1)
            {
                ++count;
            }
            if (nums[index + 2 - k] - nums[index + 1 - k] == 1)
            {
                --count;
            }
        }

        if (count == k - 1)
        {
            result.push_back(nums[index]);
        }
        else
        {
            result.push_back(-1);
        }

        return result;
    }
};
