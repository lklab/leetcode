class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<int>& visited, unordered_set<int>& path, int current) {
        visited[current] = 1;
        path.insert(current);

        for (int next : graph[current]) {
            if (visited[next] == 2 || path.find(next) != path.end()) { // check cycle
                for (int node : path) {
                    visited[node] = 2;
                }

            } else if (visited[next] == 0) {
                dfs(graph, visited, path, next);
            }
        }

        path.erase(current);
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        unordered_set<int> path;

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                dfs(graph, visited, path, i);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 1) {
                result.push_back(i);
            }
        }

        return result;
    }
};
