class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.size();

        if (n != goal.size())
        {
            return false;
        }

        char start = s[0];

        for (int i = 0; i < n; ++i)
        {
            if (start == goal[i])
            {
                bool isCan = true;

                for (int j = 0; j < n; ++j)
                {
                    if (s[j] != goal[(i + j) % n])
                    {
                        isCan = false;
                        break;
                    }
                }

                if (isCan)
                {
                    return true;
                }
            }
        }

        return false;
    }
};
