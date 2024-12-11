class Solution
{
public:
    int maximumBeauty(vector<int>& nums, int k)
    {
        unordered_map<int, int> m;
        vector<int> keys;

        for (int num : nums)
        {
            int l = max(0, num - k);
            int r = num + k + 1;

            if (m.find(l) == m.end())
            {
                keys.push_back(l);
            }
            m[l] += 1;

            if (m.find(r) == m.end())
            {
                keys.push_back(r);
            }
            m[r] -= 1;
        }

        sort(keys.begin(), keys.end());

        int result = 0;
        int val = 0;
        for (int key : keys)
        {
            val += m[key];
            result = max(result, val);
        }

        return result;
    }
};
