class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    {
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n - 1; ++i)
        {
            graph[i].push_back(i + 1);
        }

        vector<int> result;
        for (const auto& query : queries)
        {
            graph[query[0]].push_back(query[1]);

            queue<int> q;
            unordered_set<int> visited;
            q.push(0);
            int dist = 0;
            int count = 0;
            bool flag = true;

            while(flag)
            {
                if (count == 0)
                {
                    count = q.size();
                    ++dist;
                }

                int current = q.front();
                q.pop();
                visited.insert(current);
                --count;

                for (int next : graph[current])
                {
                    if (next == n - 1)
                    {
                        flag = false;
                        break;
                    }

                    if (visited.find(next) == visited.end())
                    {
                        q.push(next);
                    }
                }
            }

            result.push_back(dist);
        }

        return result;
    }
};
