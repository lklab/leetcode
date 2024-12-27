class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = -2147483648;
        int m = values[0];

        for (int i = 1; i < values.size(); ++i) {
            if (values[i] - i + m > result) {
                result = values[i] - i + m;
            }

            if (values[i] + i > m) {
                m = values[i] + i;
            }
        }

        return result;
    }
};
