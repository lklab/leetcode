class Solution
{
public:
    int maximumLength(string s)
    {
        int n = s.size();
        int result = -1;
        unordered_map<int, int> m;

        int index = 0;
        while (index < n)
        {
            char current = s[index];
            int size = 0;
            while (index < n && s[index] == current)
            {
                ++index;
                ++size;
            }

            for (int i = size; i > size - 3; --i)
            {
                int key = (current - 'a') * 1000 + i;
                m[key] += size - i + 1;

                if (m[key] >= 3)
                {
                    result = max(result, i);
                }
            }
        }

        return result;
    }
};
