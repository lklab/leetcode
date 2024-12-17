class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        int counts[26];

        for (char c : s)
        {
            counts[c - 'a'] += 1;
        }

        stack<int> stack;
        for (int i = 0; i < 26; ++i)
        {
            if (counts[i] > 0)
            {
                stack.push(i);
            }
        }

        string result;
        while (!stack.empty())
        {
            int index = stack.top();
            stack.pop();

            int count = counts[index];
            while (true)
            {
                int repeat = min(count, repeatLimit);
                for (int i = 0; i < repeat; ++i)
                {
                    result += index + 'a';
                }
                count -= repeat;

                if (count <= 0 || stack.empty())
                {
                    break;
                }

                int next = stack.top();
                result += next + 'a';
                counts[next] -= 1;
                if (counts[next] == 0)
                {
                    stack.pop();
                }
            }
        }

        return result;
    }
};
