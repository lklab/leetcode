class Solution {
private:
    bool divide(int sqr, int digits, int prefix, int n) {
        if (sqr + prefix == n) {
            return true;
        } else if (prefix > n) {
            return false;
        }

        int divider = 10;
        for (int i = 1; i < digits; ++i) {
            int right = sqr % divider;
            if (divide(sqr / divider, digits - i, right + prefix, n)) {
                return true;
            }
            divider *= 10;
        }

        return false;
    }

public:
    int punishmentNumber(int n) {
        int result = 0;

        for (int i = 1; i <= n; ++i) {
            int sqr = i * i;
            int digits = 0;
            while (sqr > 0) {
                sqr /= 10;
                ++digits;
            }

            sqr = i * i;
            if (divide(sqr, digits, 0, i)) {
                result += sqr;
            }
        }

        return result;
    }
};
