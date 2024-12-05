class Solution
{
public:
    bool canChange(string start, string target)
    {
        int n = start.size();
        int index = 0;

        for (int i = 0; i < n; ++i)
        {
            char c = start[i];
            if (c != '_')
            {
                while (index < n && target[index] == '_')
                    ++index;

                // cout << c << ", " << i << ", " << index << ", " << target[index] << endl;
                if (
                    (index == n) ||
                    (c != target[index]) ||
                    (c == 'L' && i < index) ||
                    (c == 'R' && i > index)
                )
                    return false;

                ++index;
            }
        }

        for (; index < n; ++index)
        {
            if (target[index] != '_')
                return false;
        }

        return true;
    }
};
