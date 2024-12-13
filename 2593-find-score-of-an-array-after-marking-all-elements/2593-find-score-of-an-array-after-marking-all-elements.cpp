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
        unordered_set<int> marked;

        while (!heap.empty())
        {
            auto [num, index] = heap.top();
            heap.pop();

            if (marked.find(index) == marked.end())
            {
                score += num;
                marked.insert(index - 1);
                marked.insert(index + 1);
            }
        }

        return score;
    }
};
