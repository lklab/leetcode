class Solution
{
private:
    int getBagCount(vector<int>& nums, int maxSize)
    {
        int count = nums.size();

        for (int num : nums)
        {
            count += (num - 1) / maxSize;
        }

        return count;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations)
    {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int target = nums.size() + maxOperations;

        while (l < r)
        {
            int m = (l + r) / 2;
            int val = getBagCount(nums, m);

            if (val <= target)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};
