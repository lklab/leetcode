class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<bool> isVowel(26, false);
        isVowel['a' - 'a'] = true;
        isVowel['e' - 'a'] = true;
        isVowel['i' - 'a'] = true;
        isVowel['o' - 'a'] = true;
        isVowel['u' - 'a'] = true;
        vector<int> prefix(words.size() + 1, 0);

        for (int i = 0; i < words.size(); ++i) {
            if (isVowel[words[i][0] - 'a'] && isVowel[words[i][words[i].size() - 1] - 'a']) {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i + 1] = prefix[i];
            }
        }

        // for (int s : prefix) {
        //     cout << s << ", ";
        // }
        // cout << endl;

        vector<int> result;
        for (const auto& query : queries) {
            result.push_back(prefix[query[1] + 1] - prefix[query[0]]);
        }

        return result;
    }
};
