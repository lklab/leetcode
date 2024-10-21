class Solution
{
private:
    int backtrack(string &s, int start, unordered_set<string> &substrs)
    {
        if (start == s.size())
        {
            return 0;
        }

        int max = 0;
        string substr = "";

        for (int i = start; i < s.size(); ++i)
        {
            substr += s[i];

            if (substrs.find(substr) == substrs.end())
            {
                substrs.insert(substr);
                int count = backtrack(s, i + 1, substrs) + 1;
                substrs.erase(substr);

                if (max < count)
                {
                    max = count;
                }
            }
        }

        if (max == 0)
        {
            return -1;
        }
        else
        {
            return max;
        }
    }

public:
    int maxUniqueSplit(string s)
    {
        unordered_set<string> substrs;
        return backtrack(s, 0, substrs);
    }
};
