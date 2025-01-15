class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int oneCount = 0;

        while (num2 > 0) {
            oneCount += num2 & 0x1;
            num2 >>= 1;
        }

        int result = 0;
        int mask = 0x40000000;

        while (mask > 0 && oneCount > 0) {
            if ((num1 & mask) != 0) {
                result |= mask;
                --oneCount;
            }

            mask >>= 1;
        }

        mask = 0x1;

        while (oneCount > 0) {
            if ((result & mask) == 0) {
                result |= mask;
                --oneCount;
            }

            mask <<= 1;
        }

        return result;
    }
};
