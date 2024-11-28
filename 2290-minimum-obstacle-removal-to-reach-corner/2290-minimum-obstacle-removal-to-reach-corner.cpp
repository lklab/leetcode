class Solution
{
public:
    int minimumObstacles(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int, int>>> graph(m * n);
        vector<vector<int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 }
        };

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int index = i * n + j;
                for (const auto& dir : dirs)
                {
                    int i2 = i + dir[0];
                    int j2 = j + dir[1];

                    if (i2 >= 0 && i2 < m && j2 >= 0 && j2 < n)
                    {
                        graph[index].emplace_back(grid[i2][j2], i2 * n + j2);
                    }
                }
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        vector<int> distances(m * n, numeric_limits<int>::max());
        vector<bool> visited(m * n, false);

        int target = m * n - 1;
        distances[0] = 0;
        heap.push({0, 0});

        while (!heap.empty())
        {
            auto [current_dist, current] = heap.top();
            heap.pop();

            if (visited[current]) continue;
            visited[current] = true;

            if (current == target)
            {
                return current_dist;
            }

            for (const auto& [weight, next] : graph[current])
            {
                if (!visited[next] && current_dist + weight < distances[next])
                {
                    distances[next] = current_dist + weight;
                    heap.push({distances[next], next});
                }
            }
        }

        return 0;
    }
};
