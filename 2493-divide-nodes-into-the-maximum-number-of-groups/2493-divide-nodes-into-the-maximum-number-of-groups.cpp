class Solution {
private:
    int bfs(vector<vector<int>>& graph, vector<int>& depths, vector<int>& farthests, int start) {
        queue<int> q;
        q.push(start);
        depths[start] = 1;
        farthests.push_back(start);
        int length = 1;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            int depth = depths[current];

            for (int next : graph[current]) {
                if (depths[next] == 0) {
                    q.push(next);
                    depths[next] = depth + 1;

                    if (depth == length) {
                        // farthests.clear();
                        length = depth + 1;
                    }
                    farthests.push_back(next);

                } else if (abs(depths[next] - depth) != 1) {
                    return -1;
                }
            }
        }

        return length;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> depths1(n + 1, 0);
        int result = 0;

        for (int i = 1; i <= n; ++i) {
            if (depths1[i] == 0) {
                vector<int> farthests1;
                int depth1 = bfs(graph, depths1, farthests1, i);
                if (depth1 == -1) {
                    return -1;
                }

                int maxDepth = depth1;
                for (int root : farthests1) {
                    vector<int> depths2(n + 1, 0);
                    vector<int> farthests2;
                    int depth2 = bfs(graph, depths2, farthests2, root);
                    maxDepth = max(maxDepth, depth2);
                }

                cout << i << ", " << maxDepth << endl;
                result += maxDepth;
            }
        }

        return result;
    }
};
