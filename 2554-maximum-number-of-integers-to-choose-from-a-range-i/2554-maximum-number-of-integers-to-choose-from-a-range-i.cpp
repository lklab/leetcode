class Solution
{
public:
    int maxCount(vector<int>& banned, int n, int maxSum)
    {
        unordered_set<int> bannedSet;

        for (int val : banned)
        {
            bannedSet.insert(val);
        }

        int count = 0;
        int sum = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (bannedSet.find(i) == bannedSet.end())
            {
                sum += i;
                if (sum > maxSum)
                {
                    return count;
                }
                ++count;
            }
        }

        return count;
    }
};
