class Solution
{
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int result = 0;

        // count ones
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 1)
                {
                    ++result;
                }
            }
        }

        while (m >= 2 && n >= 2)
        {
            --m;
            --n;

            for (int i = 0; i < m ; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (matrix[i+0][j+0] == 1 &&
                        matrix[i+0][j+1] == 1 &&
                        matrix[i+1][j+0] == 1 &&
                        matrix[i+1][j+1] == 1)
                    {
                        ++result;
                    }
                    else
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        return result;
    }
};
