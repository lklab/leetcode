class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26, 0);

        for (string& word : words2) {
            vector<int> counter(26, 0);
            for (char c : word) {
                ++counter[c - 'a'];
            }

            for (int i = 0; i < 26; ++i) {
                freq[i] = max(freq[i], counter[i]);
            }
        }

        vector<string> result;

        for (string& word : words1) {
            vector<int> counter(26, 0);
            for (char c : word) {
                ++counter[c - 'a'];
            }

            bool success = true;
            for (int i = 0; i < 26; ++i) {
                if (counter[i] < freq[i]) {
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
