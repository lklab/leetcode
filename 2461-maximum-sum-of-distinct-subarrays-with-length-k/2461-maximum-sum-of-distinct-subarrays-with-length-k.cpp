class Solution
{
public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        long long sum = 0;
        unordered_map<int, int> countMap;
        int exceedsCount = 0;

        int index = 0;
        for (; index < k; ++index)
        {
            int num = nums[index];
            sum += num;

            int count = 1;
            if (countMap.find(num) != countMap.end())
            {
                count += countMap[num];
            }
            countMap[num] = count;

            if (count == 2)
            {
                ++exceedsCount;
            }
        }

        long long result = 0;
        if (exceedsCount == 0)
        {
            result = sum;
        }

        for (; index < nums.size(); ++index)
        {
            int next = nums[index];
            int prev = nums[index - k];

            sum += next;
            sum -= prev;

            int count = 1;
            if (countMap.find(next) != countMap.end())
            {
                count += countMap[next];
            }
            countMap[next] = count;

            if (count == 2)
            {
                ++exceedsCount;
            }

            count = countMap[prev] - 1;
            countMap[prev] = count;

            if (count == 1)
            {
                --exceedsCount;
            }

            if (exceedsCount == 0)
            {
                result = max(result, sum);
            }
        }

        return result;
    }
};
