class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long result = 0LL;
        int ones = 0;

        for (char c : s)
        {
            if (c == '0')
            {
                result += ones;
            }
            else
            {
                ones += 1;
            }
        }

        return result;
    }
};
