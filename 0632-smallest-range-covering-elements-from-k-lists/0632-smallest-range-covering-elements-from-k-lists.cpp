struct Number
{
    int value;
    int position;

    Number(int value, int list, int index) : value(value)
    {
        position = (list << 6) + index;
    }

    bool operator<(const Number &s) const
    {
        return this->value < s.value;
    }

    bool operator>(const Number &s) const
    {
        return this->value > s.value;
    }
};

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        int k = nums.size();

        priority_queue<Number, vector<Number>, greater<Number>> pq;
        int max = -1000000;

        for (int i = 0; i < k; ++i)
        {
            int value = nums[i][0];
            pq.push(Number(value, i, 0));
            if (value > max)
            {
                max = value;
            }
        }

        int left = pq.top().value;
        int right = max;
        int minLength = right - left;

        while (true)
        {
            int min = pq.top().value;

            int length = max - min;
            if (length < minLength)
            {
                left = min;
                right = max;
                minLength = length;
            }

            int position = pq.top().position;
            int list = position >> 6;
            int index = (position & 0x3F) + 1;

            if (index >= nums[list].size())
            {
                break;
            }

            int value = nums[list][index];
            if (value > max)
            {
                max = value;
            }

            pq.pop();
            pq.push(Number(value, list, index));
        }

        return vector<int>{ left, right };
    }
};
