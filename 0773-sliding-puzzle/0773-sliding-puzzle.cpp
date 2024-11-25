class Solution
{
public:
    int slidingPuzzle(vector<vector<int>>& board)
    {
        int state = 0;
        unsigned int reset[6] = { 0x00FFFFF0, 0x00FFFF0F, 0x00FFF0FF, 0x00FF0FFF, 0x00F0FFFF, 0x000FFFFF };
        int dirs[4][2] = {
            { 0, 1 },
            { 0, -1 },
            { 1, 0 },
            { -1, 0 },
        };

        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                state |= board[i][j] << ((i * 3 + j) * 4);

                if (board[i][j] == 0)
                {
                    state |= i << 24;
                    state |= j << 28;
                }
            }
        }

        queue<int> q;
        unordered_set<int> visited;
        int target = 0x21054321;
        int depth = 0;
        int qcount = 0;

        if (state == target)
        {
            return 0;
        }

        q.push(state);
        visited.insert(state);

        while (!q.empty())
        {
            if (qcount == 0)
            {
                qcount = q.size();
                ++depth;
            }

            state = q.front();
            q.pop();
            --qcount;

            int si = (state >> 24) & 0xF;
            int sj = (state >> 28) & 0xF;
            int shift = ((si * 3 + sj) * 4);

            for (auto& dir : dirs)
            {
                int i = si + dir[0];
                int j = sj + dir[1];

                if (i < 0 || i >= 2 || j < 0 || j >= 3)
                {
                    continue;
                }

                int move = (state >> ((i * 3 + j) * 4)) & 0xF;
                int next = state | (move << shift);
                next &= reset[i * 3 + j];
                next |= i << 24;
                next |= j << 28;

                // cout << hex << state << ", " << dec << i << ", " << j << ", " << hex << next << endl;

                if (next == target)
                {
                    return depth;
                }

                if (visited.find(next) == visited.end())
                {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }

        return -1;
    }
};
