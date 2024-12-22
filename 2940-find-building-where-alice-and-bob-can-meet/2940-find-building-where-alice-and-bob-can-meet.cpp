class Solution
{
private:
    int lower_bound_in_deque(const deque<pair<int, int>>& dq, int h)
    {
        int low = 0, high = dq.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (dq[mid].first <= h) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries)
    {
        // query[0] <= query[1]가 되도록 queries를 정리
        for (auto& query : queries)
        {
            if (query[0] > query[1])
            {
                swap(query[1], query[0]);
            }
        }

        // queries에 대한 인덱스 배열 생성
        vector<int> indices(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            indices[i] = i;
        }

        // query의 1번 요소 기준으로 내림차순 인덱스 배열 정렬
        sort(indices.begin(), indices.end(), [&queries](int a, int b) {
            return queries[a][1] > queries[b][1]; // 1번 요소 기준 내림차순
        });

        vector<int> result(queries.size());
        deque<pair<int, int>> dq;
        int hidx = heights.size() - 1;

        for (int index : indices)
        {
            int a = queries[index][0];
            int b = queries[index][1];

            if (a == b || heights[a] < heights[b])
            {
                result[index] = b;
                continue;
            }

            for (; hidx > b; --hidx)
            {
                int h = heights[hidx];
                while (!dq.empty() && dq.front().first <= h)
                {
                    dq.pop_front();
                }
                dq.emplace_front(h, hidx);
            }

            int t = lower_bound_in_deque(dq, heights[a]);
            if (t == dq.size())
            {
                result[index] = -1;
            }
            else
            {
                result[index] = dq[t].second;
            }
        }

        return result;
    }
};
