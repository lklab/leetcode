class Solution
{
private:
    pair<int, int> bfs(int start, const vector<vector<int>>& graph, int n) {
        vector<int> distance(n, -1);
        queue<int> q;

        distance[start] = 0;
        q.push(start);

        int farthestNode = start;
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int neighbor : graph[current]) {
                if (distance[neighbor] == -1) { // Not visited
                    distance[neighbor] = distance[current] + 1;
                    q.push(neighbor);

                    if (distance[neighbor] > distance[farthestNode]) {
                        farthestNode = neighbor;
                    }
                }
            }
        }

        return {farthestNode, distance[farthestNode]};
    }

    int getDiameter(vector<vector<int>>& graph, int n)
    {
        // Step 1: Perform BFS from an arbitrary node (e.g., node 0) to find the farthest node
        auto [farthestNode, _] = bfs(0, graph, n);

        // Step 2: Perform BFS from the farthest node to find the diameter
        auto [_, diameter] = bfs(farthestNode, graph, n);

        return diameter;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2)
    {
        int n, m = 0;

        for (const auto& edge : edges1)
        {
            n = max(n, edge[0]);
            n = max(n, edge[1]);
        }
        for (const auto& edge : edges2)
        {
            m = max(n, edge[0]);
            m = max(n, edge[1]);
        }
        ++n;
        ++m;

        vector<vector<int>> graph1(n);
        vector<vector<int>> graph2(m);

        for (const auto& edge : edges1)
        {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for (const auto& edge : edges2)
        {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        int d1 = getDiameter(graph1, n);
        int d2 = getDiameter(graph2, m);
        int d = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        return max(max(d1, d2), d);
    }
};
