class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> tree(n);

        // make tree
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // make parents and depths
        vector<int> parents(n, -2);
        vector<int> depths(n, -1);

        queue<int> q;
        q.push(0);
        int count = 0;
        int depth = -1;
        parents[0] = -1;

        while (!q.empty()) {
            if (count == 0) {
                count = q.size();
                ++depth;
            }

            int current = q.front();
            q.pop();
            --count;
            depths[current] = depth;

            for (int next : tree[current]) {
                if (parents[next] != -2) {
                    continue;
                }

                parents[next] = current;
                q.push(next);
            }
        }

        // apply bob's costs and rewards
        int bobMoves = (depths[bob] + 1) / 2;
        bool isBobEven = depths[bob] % 2 == 0;
        for (int i = 0; i < bobMoves; ++i) {
            amount[bob] = 0;
            bob = parents[bob];
        }

        if (isBobEven) {
            amount[bob] = amount[bob] / 2;
        }

        // dfs for alice's maximum net income
        return dfs(tree, parents, amount, 0);
    }
private:
    int dfs(vector<vector<int>>& tree, vector<int>& parents, vector<int>& amount, int current) {
        int currentNet = amount[current];

        int parent = parents[current];
        int result = 0;
        bool isResultobtained = false;

        for (int next : tree[current]) {
            if (next == parent) {
                continue;
            }

            int income = dfs(tree, parents, amount, next);
            if (!isResultobtained) {
                result = income;
                isResultobtained = true;
            } else {
                result = max(result, income);
            }
        }

        return result + currentNet;
    }
};
