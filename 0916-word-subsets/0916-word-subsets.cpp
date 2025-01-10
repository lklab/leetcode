class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26, 0);
        vector<int> freqExists;

        for (string& word : words2) {
            vector<int> counter(26, 0);
            unordered_set<int> exists;
            for (char c : word) {
                ++counter[c - 'a'];
                exists.insert(c - 'a');
            }

            for (int i : exists) {
                if (freq[i] == 0) {
                    freqExists.push_back(i);
                }
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
            for (int i : freqExists) {
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
