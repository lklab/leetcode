class Solution
{
public:
    string addSpaces(string s, vector<int>& spaces)
    {
        int n = s.size() + spaces.size();
        string result;
        result.reserve(n);

        int i1 = 0;
        int i2 = 0;
        spaces.push_back(s.size());

        for (int i = 0; i < n; ++i)
        {
            if (i1 < spaces[i2])
            {
                result += s[i1];
                ++i1;
            }
            else
            {
                result += ' ';
                ++i2;
            }
        }

        return result;
    }
};
