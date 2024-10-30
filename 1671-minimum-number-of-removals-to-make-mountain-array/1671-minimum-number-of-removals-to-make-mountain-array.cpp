class Solution
{
public:
    int minimumMountainRemovals(vector<int>& nums)
    {
        int n = nums.size();
        int dpAsc[1000];
        int dpDasc[1000];
        int search[1000];
        int maxLen;

        dpAsc[0] = 0;
        search[0] = nums[0];
        maxLen = 0;

        for (int i = 1; i < n; ++i)
        {
            int num = nums[i];
            auto it = lower_bound(search, search + maxLen + 1, num);

            if (it == search + maxLen + 1)
            {
                ++maxLen;
                dpAsc[i] = maxLen;
                search[maxLen] = num;
            }
            else
            {
                int prev = it - search;
                dpAsc[i] = prev;
                search[prev] = num;
            }
        }

        dpDasc[0] = 0;
        search[0] = nums[n-1];
        maxLen = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            int num = nums[i];
            auto it = lower_bound(search, search + maxLen + 1, num);

            if (it == search + maxLen + 1)
            {
                ++maxLen;
                dpDasc[i] = maxLen;
                search[maxLen] = num;
            }
            else
            {
                int prev = it - search;
                dpDasc[i] = prev;
                search[prev] = num;
            }
        }
        
        // string debug = "";
        // for (int i = 0; i < n; ++i)
        // {
        //     debug += to_string(dpAsc[i]) + ", ";
        // }
        // cout << debug << endl;

        // debug = "";
        // for (int i = 0; i < n; ++i)
        // {
        //     debug += to_string(dpDasc[i]) + ", ";
        // }
        // cout << debug << endl;

        int result = 0;
        for (int i = 1; i < n - 1; ++i)
        {
            if (dpAsc[i] > 0 && dpDasc[i] > 0)
            {
                int count = dpAsc[i] + dpDasc[i] + 1;
                result = max(result, count);
            }
        }

        return n - result;
    }
};
