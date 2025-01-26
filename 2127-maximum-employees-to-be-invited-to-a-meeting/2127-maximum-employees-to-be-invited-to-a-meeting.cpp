class Solution {
private:
    int getLongestPath(vector<vector<int>>& reverse, int current, int ignore) {
        int path = 1;
        // cout << " call current=" << current << endl;

        for (int next : reverse[current]) {
            if (next == ignore) {
                continue;
            }

            path = max(path, getLongestPath(reverse, next, ignore) + 1);
        }

        // cout << " return current=" << current << ", path=" << path << endl;
        return path;
    }

public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> visited(n, 0);
        vector<vector<int>> reverse(n);
        int result = 0;

        for (int i = 0; i < n; ++i) {
            reverse[favorite[i]].push_back(i);

            if (visited[i] != 0) {
                continue;
            }

            unordered_set<int> path;
            int order = 1;
            int index = i;

            while (visited[index] == 0) {
                visited[index] = order;
                path.insert(index);
                ++order;
                index = favorite[index];
            }
            // cout << "index=" << index << ", order=" << order << ", visited[index]=" << visited[index] << ", length=" << order - visited[index] << endl;

            if (path.find(index) != path.end()) {
                result = max(result, order - visited[index]);
            }
        }
        // cout << "result=" << result << endl;

        fill(visited.begin(), visited.end(), 0);
        int tadpoles = 0;

        for (int i = 0; i < n; ++i) {
            int target = favorite[i];
            if (visited[i] != 0 || favorite[target] != i) {
                continue;
            }

            visited[target] = 1;

            tadpoles +=
                + getLongestPath(reverse, i, target)
                + getLongestPath(reverse, target, i);
            cout << "tadpoles=" << tadpoles << endl;
        }

        return max(result, tadpoles);
    }
};
