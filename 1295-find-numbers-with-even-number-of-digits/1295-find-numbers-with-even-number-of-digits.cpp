class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;

        for (int num : nums) {
            int digits = 0;
            while (num > 0) {
                ++digits;
                num /= 10;
            }

            if (!(digits & 0x1)) {
                ++result;
            }
        }

        return result;
    }
};
