class TrieNode {
public:
    unordered_set<int> contains;
    unordered_map<char, TrieNode> next;

    TrieNode* append(int index, char c) {
        if (next.find(c) == next.end()) {
            next[c] = TrieNode();
        }

        next[c].contains.insert(index);
        return &next[c];
    }
};

class Solution {
private:
    unordered_set<int>* countPrefix(string& word, TrieNode* prefixRoot) {
        TrieNode* current = prefixRoot;

        for (int i = 0; i < word.size(); ++i) {
            if (current -> next.find(word[i]) == current -> next.end()) {
                return nullptr;
            } else {
                current = &(current -> next[word[i]]);
            }
        }

        return &(current -> contains);
    }

    unordered_set<int>* countSuffix(string& word, TrieNode* suffixRoot) {
        TrieNode* current = suffixRoot;

        for (int i = word.size() - 1; i >= 0; --i) {
            if (current -> next.find(word[i]) == current -> next.end()) {
                return nullptr;
            } else {
                current = &(current -> next[word[i]]);
            }
        }

        return &(current -> contains);
    }

    void appendPrefix(int index, string& word, TrieNode* prefixRoot) {
        TrieNode* current = prefixRoot;

        for (int i = 0; i < word.size(); ++i) {
            current = current -> append(index, word[i]);
        }
    }

    void appendSuffix(int index, string& word, TrieNode* suffixRoot) {
        TrieNode* current = suffixRoot;

        for (int i = word.size() - 1; i >= 0; --i) {
            current = current -> append(index, word[i]);
        }
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        TrieNode prefixRoot;
        TrieNode suffixRoot;

        int result = 0;

        for (int i = words.size() - 1; i >= 0; --i) {
            unordered_set<int>* prefixSet = countPrefix(words[i], &prefixRoot);
            unordered_set<int>* suffixSet = countSuffix(words[i], &suffixRoot);

            if (prefixSet != nullptr && suffixSet != nullptr) {
                unordered_set<int> unionSet = *prefixSet;
                unionSet.insert(suffixSet -> begin(), suffixSet -> end());
                result += unionSet.size();
            }

            appendPrefix(i, words[i], &prefixRoot);
            appendSuffix(i, words[i], &suffixRoot);
        }

        return result;
    }
};
