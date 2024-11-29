class Solution
{
public:
    int minimumTime(vector<vector<int>>& grid)
    {
        if (grid[0][1] > 1 && grid[1][0] > 1)
        {
            return -1;
        }

        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> dirs = {
            { 0, 1 },
            { 0, -1 },
            { 1, 0 },
            { -1, 0}
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        vector<int> times(m * n, INT_MAX);

        int target = m * n - 1;
        heap.emplace(0, 0);
        times[0] = 0;

        while (!heap.empty())
        {
            auto [time, current] = heap.top();
            heap.pop();

            if (current == target)
            {
                return time;
            }

            int i = current / n;
            int j = current % n;

            for (auto& dir : dirs)
            {
                int i2 = i + dir.first;
                int j2 = j + dir.second;

                if (i2 >= 0 && i2 < m && j2 >= 0 && j2 < n)
                {
                    int nextTime = time + 1;
                    if (grid[i2][j2] > nextTime)
                    {
                        nextTime += (grid[i2][j2] - nextTime + 1) / 2 * 2;
                    }

                    int next = i2 * n + j2;
                    if (times[next] > nextTime)
                    {
                        times[next] = nextTime;
                        heap.emplace(nextTime, next);
                    }
                }
            }
        }

        return -1;
    }
};
