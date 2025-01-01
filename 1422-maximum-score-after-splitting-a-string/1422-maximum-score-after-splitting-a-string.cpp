class Solution {
public:
    int maxScore(string s) {
        int oneCount = 0;
        int score = 0;
        int result = s[0] == '0' ? 1 : -1;

        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') {
                ++score;
            } else {
                --score;
                ++oneCount;
            }

            result = max(result, score);
        }

        if (s[s.size() - 1] == '1') {
            ++oneCount;
        }

        return result + oneCount;
    }
};