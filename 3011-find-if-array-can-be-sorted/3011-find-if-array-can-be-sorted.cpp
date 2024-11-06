class Solution
{
public:
    bool canSortArray(vector<int>& nums)
    {
        int currentCount = 0;
        int prevMax = 0;
        int max = 0;

        for (int num : nums)
        {
            int count = 0;
            int temp = num;
            while (temp > 0)
            {
                count += temp & 1;
                temp >>= 1;
            }

            if (count != currentCount)
            {
                currentCount = count;
                prevMax = max;
                max = num;
            }
            else if (num > max)
            {
                max = num;
            }

            if (num < prevMax)
            {
                return false;
            }
        }

        return true;
    }
};
