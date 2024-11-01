class Solution
{
public:
    string makeFancyString(string s)
    {
        string result;
        result.reserve(s.size());

        char current = ' ';
        int count = 0;

        for (char c : s)
        {
            if (current != c)
            {
                current = c;
                result += c;
                count = 1;
            }
            else if (count < 2)
            {
                result += c;
                ++count;
            }
        }

        return result;
    }
};
