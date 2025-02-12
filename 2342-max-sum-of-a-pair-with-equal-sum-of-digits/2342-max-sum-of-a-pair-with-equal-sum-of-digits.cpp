class Solution {
private:
    int sumOfDigits(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int getMaxSum(const vector<int>& nums) {
        if (nums.size() < 2) {
            return -1;
        }

        int first = nums[0];
        int second = nums[1];

        if (second > first) {
            int temp = first;
            first = second;
            second = temp;
        }

        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] >= first) {
                second = first;
                first = nums[i];
            } else if (nums[i] >= second) {
                second = nums[i];
            }
        }

        return first + second;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> m;

        for (int num : nums) {
            m[sumOfDigits(num)].push_back(num);
        }

        int result = -1;

        for (const auto& pair : m) {
            result = max(result, getMaxSum(pair.second));
        }

        return result;
    }
};
