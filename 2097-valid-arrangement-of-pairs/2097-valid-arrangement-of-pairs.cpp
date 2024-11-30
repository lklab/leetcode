class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs)
    {
        // 그래프 및 진입/진출 차수 계산
        unordered_map<int, deque<int>> graph;
        unordered_map<int, int> in_degree, out_degree;

        for (auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            graph[start].push_back(end);
            out_degree[start]++;
            in_degree[end]++;
        }

        // 시작 노드 찾기 (진출 차수 > 진입 차수인 노드)
        int start_node = pairs[0][0];
        for (auto& [node, degree] : out_degree) {
            if (degree > in_degree[node]) {
                start_node = node;
                break;
            }
        }

        // 오일러 경로를 위한 DFS
        vector<vector<int>> result;
        stack<int> stk;
        stk.push(start_node);

        while (!stk.empty()) {
            int node = stk.top();
            if (!graph[node].empty()) {
                // 그래프에서 간선을 따라감
                int next_node = graph[node].front();
                graph[node].pop_front();
                stk.push(next_node);
            } else {
                // 경로를 기록
                stk.pop();
                if (!stk.empty()) {
                    result.push_back({stk.top(), node});
                }
            }
        }

        // 결과는 올바른 순서로 나와 있음
        reverse(result.begin(), result.end());
        return result;
    }
};
