class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        if (k == 0)
        {
            return 0;
        }

        int n = s.size();
        int leftCounts[3];

        int left = 0;
        for (; left < n; ++left)
        {
            ++leftCounts[s[left] - 'a'];
            if (leftCounts[0] >= k && leftCounts[1] >= k && leftCounts[2] >= k)
            {
                break;
            }
        }

        if (left == n)
        {
            return -1;
        }

        int rightCounts[3];
        int right = n - 1;
        int result = left + 1;

        for (; right >= 0; --right)
        {
            ++rightCounts[s[right] - 'a'];

            if (left == right)
            {
                --leftCounts[s[left] - 'a'];
                --left;
            }

            while (left >= 0)
            {
                int c = s[left] - 'a';
                if (leftCounts[c] + rightCounts[c] == k)
                {
                    break;
                }
                --leftCounts[c];
                --left;
            }

            int minutes = (left + 1) + (n - right);
            result = min(result, minutes);
        }

        return result;
    }
};
