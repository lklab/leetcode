class Solution
{
public:
    long long continuousSubarrays(vector<int>& nums)
    {
        int n = nums.size();
        deque<pair<int, int>> maxq;
        deque<pair<int, int>> minq;

        int i = 0, j = 0; // j 초기값을 0으로 설정
        long long result = 0;

        while (j < n) // j가 n보다 작은 동안 실행
        {
            int current = nums[j];

            // maxq 갱신
            while (!maxq.empty() && maxq.back().second <= current)
                maxq.pop_back();
            maxq.push_back({j, current});

            // minq 갱신
            while (!minq.empty() && minq.back().second >= current)
                minq.pop_back();
            minq.push_back({j, current});

            // 조건 위반 시 i를 이동
            while (!maxq.empty() && !minq.empty() &&
                   abs(maxq.front().second - minq.front().second) > 2)
            {
                if (maxq.front().first == i)
                    maxq.pop_front();
                if (minq.front().first == i)
                    minq.pop_front();
                ++i;
            }

            // 현재 윈도우 크기를 결과에 추가
            result += (j - i + 1);
            ++j;
        }

        return result;

        // int n = nums.size();
        // deque<pair<int, int>> maxq;
        // deque<pair<int, int>> minq;

        // int i = 0;
        // int j = 1;
        // int result = 0;

        // maxq.push_back({0, nums[0]});
        // minq.push_back({0, nums[0]});

        // while (i < n && j < n)
        // {
        //     int current = nums[j];

        //     int max = maxq.front().second;
        //     int min = minq.front().second;

        //     if (abs(max - current) > 2 || abs(min - current) > 2)
        //     {
        //         result += j - i;

        //         if (maxq.front().first == i)
        //             maxq.pop_front();
        //         if (minq.front().first == i)
        //             minq.pop_front();
        //         ++i;
        //     }
        //     else
        //     {
        //         maxq.push_back({j, current});
        //         while (maxq.front().second < current)
        //             maxq.pop_front();
        //         minq.push_back({j, current});
        //         while (minq.front().second > current)
        //             minq.pop_front();
        //         ++j;
        //     }
        // }

        // int remain = j - i;
        // result += remain * (remain + 1) / 2;
        // return result;
    }
};
