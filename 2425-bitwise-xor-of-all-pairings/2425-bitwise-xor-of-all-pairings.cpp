class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int bitCount[32] = {0};

        for (int num : nums1) {
            int bit = 0;
            while (num > 0) {
                bitCount[bit] += (num & 0x1) * n2;
                bitCount[bit] %= 2;
                num >>= 1;
                ++bit;
            }
        }

        for (int num : nums2) {
            int bit = 0;
            while (num > 0) {
                bitCount[bit] += (num & 0x1) * n1;
                bitCount[bit] %= 2;
                num >>= 1;
                ++bit;
            }
        }

        int result = 0;
        for (int i = 31; i >= 0; --i) {
            result <<= 1;
            result += bitCount[i] % 2;
        }

        return result;
    }
};
