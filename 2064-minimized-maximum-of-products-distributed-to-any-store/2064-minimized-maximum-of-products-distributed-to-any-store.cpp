class Solution
{
public:
    int minimizedMaximum(int n, vector<int>& quantities)
    {
        int l = (accumulate(quantities.begin(), quantities.end(), 0LL) + n - 1) / n;
        int r = *max_element(quantities.begin(), quantities.end());

        while (l < r)
        {
            int m = (l + r) / 2;
            int result = 0;

            for (int quantity : quantities)
            {
                result += (quantity + m - 1) / m;
            }

            if (result > n)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        return l;
    }
};
