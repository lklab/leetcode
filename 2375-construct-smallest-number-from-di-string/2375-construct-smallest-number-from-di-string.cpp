class Solution {
public:
    string smallestNumber(string pattern) {
        vector<bool> used(10, false);
        string result(pattern.size() + 1, '0');

        for (int i = 1; i <= 9; ++i) {
            result[0] = i + '0';
            used[i] = true;
            if (dfs(pattern, 0, i, used, result)) {
                break;
            }
            used[i] = false;
        }

        return result;
    }

private:
    bool dfs(string& pattern, int index, int current, vector<bool>& used, string& result) {
        if (index >= pattern.size()) {
            return true;
        }

        if (pattern[index] == 'I') {
            for (int i = current + 1; i <= 9; ++i) {
                if (!used[i]) {
                    used[i] = true;
                    result[index + 1] = i + '0';
                    if (dfs(pattern, index + 1, i, used, result)) {
                        return true;
                    }
                    used[i] = false;
                }
            }
        } else {
            for (int i = current - 1; i >= 1; --i) {
                if (!used[i]) {
                    used[i] = true;
                    result[index + 1] = i + '0';
                    if (dfs(pattern, index + 1, i, used, result)) {
                        return true;
                    }
                    used[i] = false;
                }
            }
        }

        return false;
    }
};
