class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix)
    {
        int n = matrix[0].size();
        unordered_map<bitset<300>, int> map;

        bitset<300> mask;
        for (int i = 0; i < n; ++i)
        {
            mask[i] = 1;
        }

        for (auto& row : matrix)
        {
            bitset<300> bset;

            for (int i = 0; i < n; ++i)
            {
                bset[i] = row[i];
            }

            if (map.find(bset) == map.end())
            {
                map[bset] = 1;
            }
            else
            {
                ++map[bset];
            }

            bset ^= mask;

            if (map.find(bset) == map.end())
            {
                map[bset] = 1;
            }
            else
            {
                ++map[bset];
            }
        }

        int result = 0;
        for(const auto& pair : map)
        {
            result = max(result, pair.second);
        }

        return result;
    }
};
