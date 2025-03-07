class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // bitset<1000001> isNotPrime;
        bool isNotPrime[1000001] = { false };
        memset(isNotPrime, 0, sizeof(isNotPrime));
        int sqrtRight = (int)sqrt(right);

        for (int i = 2; i <= sqrtRight; ++i) {
            if (!isNotPrime[i]) {
                for (int j = i * 2; j <= right; j += i) {
                    isNotPrime[j] = true;
                    // cout << j << endl;
                }
            }
        }

        int minDist = -1;
        int l = -1;
        int resultL = -1;
        int resultR = -1;
        left = max(left, 2);

        for (int i = left; i <= right; ++i) {
            if (!isNotPrime[i]) {
                if (l != -1) {
                    int dist = i - l;

                    if (minDist == -1 || minDist > dist) {
                        minDist = dist;
                        resultL = l;
                        resultR = i;
                    }
                }

                l = i;
            }
        }

        return { resultL, resultR };
    }
};
