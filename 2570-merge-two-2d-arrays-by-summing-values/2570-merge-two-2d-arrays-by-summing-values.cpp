class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int idx1 = 0, idx2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        while (idx1 < n1 && idx2 < n2) {
            if (nums1[idx1][0] == nums2[idx2][0]) {
                result.push_back({nums1[idx1][0], nums1[idx1][1] + nums2[idx2][1]});
                ++idx1;
                ++idx2;
            } else if (nums1[idx1][0] < nums2[idx2][0]) {
                result.push_back(nums1[idx1]);
                ++idx1;
            } else {
                result.push_back(nums2[idx2]);
                ++idx2;
            }
        }

        result.insert(result.end(), nums1.begin() + idx1, nums1.end());
        result.insert(result.end(), nums2.begin() + idx2, nums2.end());

        return result;
    }
};
