class Solution {
private:
    void dfs(string& tiles, string& current, unordered_set<string>& letters, vector<bool>& used) {
        letters.insert(current);

        for (int i = 0; i < tiles.size(); ++i) {
            if (!used[i]) {
                string next = current + tiles[i];
                // if (letters.find(next) == letters.end()) {
                    used[i] = true;
                    dfs(tiles, next, letters, used);
                    used[i] = false;
                // }
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> letters;
        vector<bool> used(tiles.size(), false);
        string current = "";
        dfs(tiles, current, letters, used);
        return letters.size() - 1;
    }
};
