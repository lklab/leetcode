class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long result = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            result += i - m[nums[i] - i];
            ++m[nums[i] - i];
        }

        return result;
    }
};
