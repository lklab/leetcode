class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> m;

        for (string& word : words2) {
            unordered_map<char, int> counter;
            for (char c : word) {
                ++counter[c];
            }

            for (const auto& pair : counter) {
                m[pair.first] = max(m[pair.first], pair.second);
            }
        }

        vector<string> result;

        for (string& word : words1) {
            unordered_map<char, int> counter;
            for (char c : word) {
                ++counter[c];
            }

            bool success = true;
            for (const auto& pair : m) {
                if (counter[pair.first] < pair.second) {
                    success = false;
                    break;
                }
            }

            if (success) {
                result.push_back(word);
            }
        }

        return result;
    }
};
