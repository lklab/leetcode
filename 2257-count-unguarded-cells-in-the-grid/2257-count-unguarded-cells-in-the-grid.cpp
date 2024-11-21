class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        int field[m][n];
        memset(field, 0, sizeof(field));

        for (auto& wall : walls)
        {
            field[wall[0]][wall[1]] = 3;
        }

        for (auto& guard : guards)
        {
            field[guard[0]][guard[1]] = 2;
        }

        int dirs[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        for (auto& guard : guards)
        {
            for (auto& dir : dirs)
            {
                int i = guard[0] + dir[0];
                int j = guard[1] + dir[1];

                while (i >= 0 && i < m && j >= 0 && j < n)
                {
                    if (field[i][j] >= 2)
                    {
                        break;
                    }
                    field[i][j] = 1;

                    i += dir[0];
                    j += dir[1];
                }
            }
        }

        int result = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (field[i][j] == 0)
                {
                    ++result;
                }
            }
        }

        return result;
    }
};
