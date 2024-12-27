class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = -2147483648;
        int left = values[0];

        for (int i = 1; i < values.size(); ++i) {
            if (values[i] - i + left > result) {
                result = values[i] - i + left;
            }

            if (values[i] + i > left) {
                left = values[i] + i;
            }
        }

        return result;
    }
};
