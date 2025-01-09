class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0;
        int n = pref.size();

        for (const auto word : words) {
            if (word.size() < n) {
                continue;
            }

            bool match = true;
            for (int i = 0; i < n; ++i) {
                if (word[i] != pref[i]) {
                    match = false;
                    break;
                }
            }

            if (match)
                ++result;
        }

        return result;
    }
};
