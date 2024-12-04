class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int n1 = str1.size();
        int n2 = str2.size();
        int i1 = 0;
        int i2 = 0;

        for (; i1 < n1; ++i1)
        {
            int diff = str2[i2] - str1[i1];
            if (diff == 0 || diff == 1 || diff == -25)
            {
                ++i2;
            }

            if (i2 == n2)
            {
                return true;
            }
        }

        return false;
    }
};
