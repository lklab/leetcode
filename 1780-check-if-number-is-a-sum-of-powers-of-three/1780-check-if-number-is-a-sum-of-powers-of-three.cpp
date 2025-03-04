class Solution {
public:
    bool checkPowersOfThree(int n) {
        int div = 4782969;

        while (div > 1) {
            if (n > div) {
                n -= div;
            } else if (n == div) {
                return true;
            }

            div /= 3;
        }

        return n == 1;
    }
};
