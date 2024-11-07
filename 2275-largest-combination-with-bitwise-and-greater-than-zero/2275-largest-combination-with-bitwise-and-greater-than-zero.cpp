class Solution
{
public:
    int largestCombination(vector<int>& candidates)
    {
        int counts[24] = { 0 };

        for (int candidate : candidates)
        {
            int bit = 0;
            while (candidate > 0)
            {
                counts[bit] += candidate & 1;
                candidate >>= 1;
                ++bit;
            }
        }

        int result = 0;
        for (int count : counts)
        {
            result = max(result, count);
        }

        return result;
    }
};
