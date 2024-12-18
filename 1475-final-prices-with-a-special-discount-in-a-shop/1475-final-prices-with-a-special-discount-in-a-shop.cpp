class Solution
{
public:
    vector<int> finalPrices(vector<int>& prices)
    {
        for (int i = 0; i < prices.size(); ++i)
        {
            int value = prices[i];
            for (int j = i + 1; j < prices.size(); ++j)
            {
                if (value >= prices[j])
                {
                    prices[i] = value - prices[j];
                    break;
                }
            }
        }

        return prices;
    }
};
