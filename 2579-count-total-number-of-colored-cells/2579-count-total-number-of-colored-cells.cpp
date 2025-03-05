class Solution {
public:
    long long coloredCells(int n) {
        if (n == 1) {
            return 1;
        }

        --n;
        return n * (8LL + (n - 1) * 4LL) / 2 + 1;
    }
};
