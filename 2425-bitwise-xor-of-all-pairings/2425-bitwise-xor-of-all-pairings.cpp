class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int result = 0;

        if (n1 % 2 == 1) {
            for (int num : nums2) {
                result ^= num;
            }
        }

        if (n2 % 2 == 1) {
            for (int num : nums1) {
                result ^= num;
            }
        }

        return result;
    }
};
