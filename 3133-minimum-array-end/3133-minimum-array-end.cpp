class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long long result = 0;
        long long mask = 1;
        --n;

        while (n > 0 || x > 0)
        {
            if ((x & 1) == 1)
            {
                result |= mask;
            }
            else
            {
                if ((n & 1) == 1)
                {
                    result |= mask;
                }
                n >>= 1;
            }

            x >>= 1;
            mask <<= 1;
        }

        return result;
    }
};
