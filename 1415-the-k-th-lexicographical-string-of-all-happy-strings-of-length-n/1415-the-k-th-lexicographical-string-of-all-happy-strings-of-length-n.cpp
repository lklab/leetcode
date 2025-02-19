class Solution {
public:
    string getHappyString(int n, int k) {
        string result(n, 'a');
        dfs(n, k, 0, result);
        return k == 0 ? result : "";
    }
private:
    void dfs(int n, int& k, int index, string& result) {
        if (k == 0) {
            return;
        }

        if (index == n) {
            --k;
            // cout << "k: " << k << ", result: " << result << endl;
            return;
        }

        for (int i = 0; i < 3 && k > 0; ++i) {
            if (index == 0 || result[index - 1] != (i + 'a')) {
                result[index] = i + 'a';
                dfs(n, k, index + 1, result);
            }
        }
    }
};
