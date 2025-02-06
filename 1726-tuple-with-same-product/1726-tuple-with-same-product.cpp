class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counts;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                counts[nums[i] * nums[j]] += 1;
            }
        }

        int result = 0;
        for (auto [product, count] : counts) {
            result += count * (count - 1) / 2;
        }

        return result * 8;
    }
};

