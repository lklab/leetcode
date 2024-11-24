class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        long long sum = 0;

        bool zeroExists = false;
        int negCount = 0;
        int minElement = 100000;

        for (auto& row : matrix)
        {
            for (int element : row)
            {
                if (element == 0)
                {
                    zeroExists = true;
                }
                else if (element < 0)
                {
                    ++negCount;
                    element = -element;
                }

                sum += element;
                minElement = min(minElement, element);
            }
        }

        if (!zeroExists && (negCount % 2) == 1)
        {
            sum = sum - minElement - minElement;
        }

        return sum;
    }
};
