class Solution
{
public:
    long long maxKelements(vector<int>& nums, int k)
    {
        priority_queue<int> pq;

        for (int num : nums)
        {
            pq.push(num);
        }

        long long result = 0LL;

        for (int i = 0; i < k; ++i)
        {
            int value = pq.top();
            pq.pop();

            result += value;
            pq.push((value + 2) / 3);
        }

        return result;
    }
};
