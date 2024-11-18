class Solution
{
public:
    vector<int> decrypt(vector<int>& code, int k)
    {
        int n = code.size();

        int sum = 0;
        int index = 0;
        int count = k;
        int dir = k != 0 ? k / abs(k) : 0;

        while (count != 0)
        {
            index = ((index + dir) % n + n) % n;
            sum += code[index];
            count -= dir;
        }

        vector<int> result(n, 0);

        if (dir == 0)
        {
            for (int i = 0; i < n; ++i)
            {
                result[i] = 0;
            }
        }
        else if (dir > 0)
        {
            for (int i = 0; i < n; ++i)
            {
                result[i] = sum;
                sum -= code[(i + dir) % n];
                sum += code[(i + k + 1) % n];
            }
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                result[i] = sum;
                sum += code[i];
                sum -= code[((i + k) % n + n) % n];
            }
        }

        return result;
    }
};
