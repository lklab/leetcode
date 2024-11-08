class Solution
{
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        int n = nums.size();
        vector<int> result(n);

        int mask = 0;
        for (int i = 0; i < maximumBit; ++i)
        {
            mask <<= 1;
            mask |= 1;
        }

        int temp = 0;
        for (int i = 0; i < n; ++i)
        {
            temp ^= nums[i];
            result[n - i - 1] = ~temp & mask;
        }

        return result;
    }
};
