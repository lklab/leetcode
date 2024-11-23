class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box)
    {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> result(n, vector<char>(m, '.'));

        for (int i = 0; i < m; ++i)
        {
            int j = n - 1;
            int x = m - i - 1;
            int y = n - 1;

            while (j >= 0)
            {
                int count = 0;

                while (j >= 0)
                {
                    if (box[i][j] == '#')
                    {
                        ++count;
                    }
                    else if (box[i][j] == '*')
                    {
                        result[j][x] = '*';
                        --j;
                        break;
                    }

                    --j;
                }

                while (count > 0)
                {
                    result[y][x] = '#';
                    --y;
                    --count;
                }

                y = j;
            }
        }

        return result;
    }
};
