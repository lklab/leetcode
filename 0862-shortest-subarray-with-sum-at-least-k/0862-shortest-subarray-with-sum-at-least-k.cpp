class Solution
{
public:
    int shortestSubarray(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0); // 누적 합
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        deque<int> dq; // 인덱스를 저장하는 덱
        int minLength = INT_MAX;

        for (int i = 0; i <= n; i++) {
            // 조건을 만족하는 부분 배열 찾기
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }

            // 덱에 현재 인덱스를 추가하기 전에 유지 조건 확인
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
