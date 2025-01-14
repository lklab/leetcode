class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int counter[51] = {0};
        vector<int> result(n);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (++counter[A[i]] == 2) {
                ++count;
            }

            if (++counter[B[i]] == 2) {
                ++count;
            }

            result[i] = count;
        }

        return result;
    }
};
