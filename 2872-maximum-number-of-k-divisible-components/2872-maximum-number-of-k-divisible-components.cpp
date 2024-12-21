class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k)
    {
        // Adjacency list representation of the tree
        vector<vector<int>> tree(n);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // Calculate the total sum of all node values
        long long totalSum = 0;
        for (int value : values) {
            totalSum += value;
        }

        // If the total sum is not divisible by k, return 1 (cannot split)
        if (totalSum % k != 0) {
            return 1;
        }

        // To keep track of visited nodes
        vector<bool> visited(n, false);

        // Result variable to count maximum components
        int maxComponents = 0;

        // DFS function to calculate the sum of the component
        function<long long(int)> dfs = [&](int node) {
            visited[node] = true;
            long long sum = values[node];

            for (int neighbor : tree[node]) {
                if (!visited[neighbor]) {
                    long long subtreeSum = dfs(neighbor);

                    // If the subtree sum is divisible by k, split here
                    if (subtreeSum % k == 0) {
                        maxComponents++;
                    } else {
                        sum += subtreeSum;
                    }
                }
            }

            return sum;
        };

        // Start DFS from node 0
        dfs(0);

        // Increment for the final component
        return maxComponents + 1;
    }
};
