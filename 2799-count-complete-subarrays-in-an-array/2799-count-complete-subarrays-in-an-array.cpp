class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> unique_elements(nums.begin(), nums.end());
        int total_unique = unique_elements.size();
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> freq;
            int distinct = 0;
            for (int j = i; j < n; ++j) {
                if (++freq[nums[j]] == 1) {
                    ++distinct;
                }
                if (distinct == total_unique) {
                    ++count;
                }
            }
        }
        return count;
    }
};
