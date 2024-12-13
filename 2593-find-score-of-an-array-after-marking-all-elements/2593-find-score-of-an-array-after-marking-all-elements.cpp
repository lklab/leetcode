class Solution
{
public:
    long long findScore(vector<int>& nums)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        for (int i = 0; i < nums.size(); ++i)
        {
            heap.emplace(nums[i], i);
        }

        long long score = 0;
        vector<int> marked(nums.size() + 2, 0);

        while (!heap.empty())
        {
            auto [num, index] = heap.top();
            heap.pop();

            if (marked[index + 1] == 0)
            {
                score += num;
                marked[index] = 1;
                marked[index + 2] = 1;
            }
        }

        return score;
    }
};
