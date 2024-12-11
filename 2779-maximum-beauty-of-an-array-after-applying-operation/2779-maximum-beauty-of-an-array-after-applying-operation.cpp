class Solution
{
public:
    int maximumBeauty(vector<int>& nums, int k)
    {
        unordered_map<int, int> m;

        for (int num : nums)
        {
            m[max(0, num - k)] += 1;
            m[num + k + 1] -= 1;
        }

        vector<int> keys;
        for (const auto& pair : m)
        {
            keys.push_back(pair.first);
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
