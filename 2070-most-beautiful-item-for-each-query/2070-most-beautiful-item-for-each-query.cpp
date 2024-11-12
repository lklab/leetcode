class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    {
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0];
        });

        unordered_map<int, int> priceMap;
        vector<int> priceList;
        int minBeauty = 0;
        int currentPrice = 0;

        for (vector<int>& item : items)
        {
            int price = item[0];
            minBeauty = max(minBeauty, item[1]);
            priceMap[price] = minBeauty;
            if (currentPrice != price)
            {
                currentPrice = price;
                priceList.push_back(price);
            }
        }

        sort(priceList.begin(), priceList.end());
        int maxBeauty = minBeauty;

        for (int i = 0; i < queries.size(); ++i)
        {
            if (priceMap.find(queries[i]) != priceMap.end())
            {
                queries[i] = priceMap[queries[i]];
                continue;
            }

            auto it = lower_bound(priceList.begin(), priceList.end(), queries[i]);

            if (it == priceList.end())
            {
                queries[i] = maxBeauty;
            }
            else if (it == priceList.begin())
            {
                queries[i] = 0;
            }
            else
            {
                queries[i] = priceMap[*(it - 1)];
            }
        }

        return queries;
    }
};
