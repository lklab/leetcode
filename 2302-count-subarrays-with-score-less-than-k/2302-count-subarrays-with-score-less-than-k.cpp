class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0LL;
        int len = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        long long result = 0LL;

        while (l < n) {
            while (r < n) {
                if ((sum + nums[r]) * (len + 1) >= k) {
                    break;
                }

                sum += nums[r];
                ++len;
                ++r;
            }

            // cout << l << ", " << r << endl;

            result += r - l;

            sum -= nums[l];
            --len;
            ++l;

            // if (r < l) {
            //     r = l;
            //     sum = 0LL;
            //     len = 0;
            // }
        }

        return result;
    }
};
