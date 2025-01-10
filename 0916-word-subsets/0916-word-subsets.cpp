class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freq[26] = {0};
        int counter[26];

        for (string& word : words2) {
            memset(counter, 0, sizeof(counter));
            for (char c : word) {
                ++counter[c - 'a'];
            }

            for (int i = 0; i < 26; ++i) {
                freq[i] = max(freq[i], counter[i]);
            }
        }

        vector<string> result;

        for (string& word : words1) {
            memset(counter, 0, sizeof(counter));
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
