class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> counts(37, 0);

        for (int i = 1; i <= n; ++i) {
            int num = i;
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            ++counts[sum];
        }

        int result = 0;
        int largest = 0;

        for (int i = 1; i < 37; ++i) {
            if (counts[i] > largest) {
                result = 1;
                largest = counts[i];
            } else if (counts[i] == largest) {
                ++result;
            }
        }

        return result;
    }
};
