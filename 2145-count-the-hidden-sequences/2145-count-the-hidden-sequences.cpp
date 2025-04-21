class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long minVal = 0;
        long maxVal = 0;
        long sum = 0;

        for (int diff : differences) {
            sum += diff;
            minVal = min(minVal, sum);
            maxVal = max(maxVal, sum);
        }

        // int offset = lower - minVal;
        return max((int)(upper - maxVal - lower + minVal + 1), 0);
    }
};
