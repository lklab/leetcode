class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> heap;

        for (int num : nums) {
            heap.push(num);
        }

        int count = 0;
        while (heap.top() < k) {
            unsigned long long x = heap.top();
            heap.pop();
            unsigned long long y = heap.top();
            heap.pop();

            heap.push(x * 2 + y);
            ++count;
        }

        return count;
    }
};
