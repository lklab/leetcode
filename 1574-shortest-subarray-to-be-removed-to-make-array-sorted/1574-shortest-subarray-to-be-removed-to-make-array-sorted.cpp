class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int>& arr)
    {
        int n = arr.size();

        int l = 0;
        for (; l < n - 1; ++l)
        {
            if (arr[l] > arr[l + 1])
            {
                break;
            }
        }

        if (l == n - 1)
        {
            return 0;
        }

        int r = n - 1;
        for (; r > 0; --r)
        {
            if (arr[r] < arr[r - 1])
            {
                break;
            }
        }

        int result = r;
        int rIndex = r;

        for (int i = 0; i <= l; ++i)
        {
            while (arr[i] > arr[rIndex] && rIndex < n - 1)
            {
                ++rIndex;
            }

            if (arr[i] <= arr[rIndex])
            {
                result = min(result, rIndex - i - 1);
            }
            else
            {
                result = min(result, n - i - 1);
            }
        }

        return result;
    }
};
