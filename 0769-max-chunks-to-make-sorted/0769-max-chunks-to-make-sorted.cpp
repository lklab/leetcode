class Solution
{
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> indexes(n);
        for (int i = 0; i < n; ++i) {
            indexes[i] = i;
        }
        sort(indexes.begin(), indexes.end(), [&arr](int a, int b) {
            return arr[a] < arr[b];
        });

        int chunkMin = 0;
        int chunkMax = 0;
        int count = 0;
        int result = 0;

        for (int i = 0; i < n; ++i)
        {
            int j = indexes[i];
            chunkMax = max(chunkMax, j);
            if (chunkMax == n - 1)
            {
                ++result;
                break;
            }
            ++count;
            if (count == (chunkMax - chunkMin + 1))
            {
                chunkMin = i + 1;
                chunkMax = chunkMin;
                count = 0;
                ++result;
            }
        }

        return result;
    }
};
