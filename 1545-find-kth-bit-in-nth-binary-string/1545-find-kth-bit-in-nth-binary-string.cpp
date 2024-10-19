class Solution
{
public:
    char findKthBit(int n, int k)
    {
        n = 0;
        int temp = k;
        while (temp > 0)
        {
            ++n;
            temp >>= 1;
        }

        int arr[(1 << n) - 1];
        arr[0] = 0;
        int currentSize = 1;

        for (int i = 1; i < n; ++i)
        {
            arr[currentSize] = 1;
            int nextSize = (currentSize << 1) + 1;
            for (int j = 1; j <= currentSize; ++j)
            {
                arr[currentSize + j] = !arr[currentSize - j];
            }
            currentSize = nextSize;
        }

        if (arr[k - 1] == 0)
            return '0';
        else
            return '1';
    }
};
