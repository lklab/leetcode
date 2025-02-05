class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int difIndex = -1;
        int difCount = 0;

        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                ++difCount;
                if (difCount > 2) {
                    return false;
                } else if (difIndex == -1) {
                    difIndex = i;
                } else if (s1[difIndex] != s2[i] || s1[i] != s2[difIndex]) {
                    return false;
                }
            }
        }

        return difCount != 1;
    }
};
