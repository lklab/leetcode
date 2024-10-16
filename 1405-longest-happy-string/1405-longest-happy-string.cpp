class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        int total = a + b + c;
        string result;
        result.reserve(total);

        int counts[3] = { a, b, c };
        auto cmp = [&counts](int x, int y) {
            return counts[x] < counts[y];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < 3; ++i)
        {
            if (counts[i] > 0)
            {
                pq.push(i);
            }
        }

        string concats[6] = { "a", "aa", "b", "bb", "c", "cc" };

        int current = pq.top();
        pq.pop();

        while (current >= 0)
        {
            int next = -1;
            int chars = 2;
            if (pq.size() > 0)
            {
                next = pq.top();
                pq.pop();
                int nextMax = counts[next];
                if (nextMax > total - nextMax || counts[current] < 2)
                {
                    chars = 1;
                }
            }
            else
            {
                if (counts[current] < 2)
                {
                    chars = 1;
                }
            }

            result += concats[current * 2 + chars - 1];
            total -= chars;
            counts[current] -= chars;

            if (counts[current] > 0)
            {
                pq.push(current);
            }
            current = next;
        }

        return result;
    }
};
