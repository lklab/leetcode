class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto pit = upper_bound(nums.begin(), nums.end(), 0);
        auto nit = lower_bound(nums.begin(), nums.end(), 0);

        // cout << (int)nums.size() - (int)(pit - nums.begin()) << endl;
        // cout << (int)(nit - nums.begin()) << endl;

        return max((int)nums.size() - (int)(pit - nums.begin()), (int)(nit - nums.begin()));
    }
};
