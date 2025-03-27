class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int half = (n + 2) / 2;

        // find dominant
        int dominant = 0;
        unordered_map<int, int> counter;
        for (int num : nums) {
            int count = ++counter[num];

            if (count >= half) {
                dominant = num;
                break;
            }
        }

        // split
        int dominantCount = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == dominant) {
                ++dominantCount;
                int leftHalf = (i + 3) / 2;
                if (dominantCount >= leftHalf) {
                    int rightHalf = (n - i + 1) / 2;
                    int rightCount = 0;
                    for (int j = i + 1; j < n; ++j) {
                        if (nums[j] == dominant) {
                            ++rightCount;
                            if (rightCount >= rightHalf) {
                                return i;
                            }
                        }
                    }
                    return -1;
                }
            }
        }

        return -1;
    }
};
