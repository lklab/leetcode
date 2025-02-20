class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> numSet;

        for (const auto& numStr : nums) {
            int num = 0;
            for (int i = 0; i < n; ++i) {
                if (numStr[n - i - 1] == '1') {
                    num += 1 << i;
                }
            }

            cout << num << endl;
            numSet.insert(num);
        }

        int result = 0;
        for (int i = 0; i <= n; ++i) {
            if (numSet.find(i) == numSet.end()) {
                result = i;
                break;
            }
        }

        string resultStr(n, '0');
        for (int i = 0; i < n; ++i) {
            resultStr[n - i - 1] = (result & 0x1) + '0';
            result >>= 1;
        }

        return resultStr;
    }
};
