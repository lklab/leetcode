class Solution
{
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
    {
        vector<int> subs;
        bool flag = false;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            bool isEven = (nums[i] + nums[i + 1]) % 2 == 0;
            if (!flag && !isEven)
            {
                subs.push_back(i);
                flag = true;
            }
            else if (flag && isEven)
            {
                subs.push_back(i);
                flag = false;
            }
        }

        if (subs.size() % 2 == 1)
        {
            subs.push_back(nums.size() - 1);
        }

        vector<bool> result;

        for (auto& query : queries)
        {
            if (query[0] == query[1])
            {
                result.push_back(true);
                continue;
            }

            auto iter0 = lower_bound(subs.begin(), subs.end(), query[0]);
            auto iter1 = lower_bound(subs.begin(), subs.end(), query[1]);

            if (iter0 == subs.end() || iter1 == subs.end())
            {
                result.push_back(false);
                continue;
            }

            int index0 = *iter0;
            int index1 = *iter1;

            if (index0 % 2 == 0 && subs[index0] == query[0])
            {
                ++index0;
            }

            result.push_back(index0 % 2 == 1 && index1 % 2 == 1 && index0 == index1);
        }

        return result;
    }
};
