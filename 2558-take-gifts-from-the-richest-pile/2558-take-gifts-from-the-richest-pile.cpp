class Solution
{
public:
    long long pickGifts(vector<int>& gifts, int k)
    {
        long long sum = 0;
        priority_queue<int, vector<int>> q;
        for (int gift : gifts)
        {
            q.push(gift);
            sum += gift;
        }

        for (int i = 0; i < k; ++i)
        {
            int gift = q.top();
            q.pop();

            int newGift = (int)sqrt(gift);
            q.push(newGift);
            sum -= gift - newGift;
        }

        return sum;
    }
};
