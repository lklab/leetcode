class Solution
{
public:
    int findChampion(int n, vector<vector<int>>& edges)
    {
        // make graph
        vector<unordered_set<int>> strongGraph(n);
        vector<int> weakGraph(n, -1);

        for (auto& edge : edges)
        {
            strongGraph[edge[0]].insert(edge[1]);
            weakGraph[edge[1]] = edge[0];
        }

        // find top node from any node
        int topNode = 0;
        while (weakGraph[topNode] != -1)
        {
            topNode = weakGraph[topNode];
        }

        // use bfs to check if all nodes can be visited from the top node
        queue<int> q;
        unordered_set<int> visited;
        q.push(topNode);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            visited.insert(node);

            for (int next : strongGraph[node])
            {
                if (visited.find(next) == visited.end())
                {
                    q.push(next);
                }
            }
        }

        return visited.size() == n ? topNode : -1;
    }
};
