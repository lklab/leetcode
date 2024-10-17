class Solution
{
public:
    int maximumSwap(int num)
    {
        int max = num % 10;
        int maxPos = 0;
        int swapPos0 = -1;
        int swapPos1 = -1;
        int diff = -1;

        int test = num;
        int pos = 0;

        while (test > 0)
        {
            int digit = test % 10;
            if (digit > max)
            {
                max = digit;
                maxPos = pos;
            }
            else if (digit < max)
            {
                swapPos0 = maxPos;
                swapPos1 = pos;
                diff = max - digit;
            }

            test /= 10;
            ++pos;
        }

        int digits[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

        if (swapPos0 != -1)
        {
            num += diff * digits[swapPos1];
            num -= diff * digits[swapPos0];
        }

        return num;
    }
};
