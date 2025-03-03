class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> less;
        vector<int> greater;
        int pivotCount = 0;

        for (int num : nums) {
            if (num < pivot) {
                less.push_back(num);
            } else if (num > pivot) {
                greater.push_back(num);
            } else {
                ++pivotCount;
            }
        }

        copy(less.begin(), less.end(), nums.begin());
        fill_n(nums.begin() + less.size(), pivotCount, pivot);
        copy(greater.begin(), greater.end(), nums.begin() + less.size() + pivotCount);

        return nums;
    }
};
