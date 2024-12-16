class Solution
{
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (int i = 0; i < nums.size(); ++i)
        {
            heap.emplace(nums[i], i);
        }

        for (int i = 0; i < k; ++i)
        {
            auto [num, index] = heap.top();
            heap.pop();
            num *= multiplier;
            heap.emplace(num, index);
            nums[index] = num;
        }

        return nums;
    }
};
