class Solution {
public:
    int minimumLength(string s) {
        int counter[26] = {0};

        for (char c : s) {
            ++counter[c - 'a'];
        }

        int result = 0;
        for (int count : counter) {
            result += ((count + 1) % 2 + 1) * (count != 0);
        }

        return result;
    }
};
