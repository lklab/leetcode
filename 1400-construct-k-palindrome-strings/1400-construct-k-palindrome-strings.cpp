class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) {
            return false;
        }

        int counter[26] = {0};
        for (char c : s) {
            ++counter[c - 'a'];
        }

        int oddCount = 0;
        for (int count : counter) {
            if (count % 2 == 1) {
                ++oddCount;
            }
        }

        return oddCount <= k;
    }
};
