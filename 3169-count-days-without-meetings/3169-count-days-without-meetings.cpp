class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        vector<int> indexes(n, 0);
        for (int i = 0; i < n; ++i) {
            indexes[i] = i;
        }

        sort(indexes.begin(), indexes.end(),
            [&meetings](int a, int b) {
                return meetings[a][0] < meetings[b][0];
            });

        int result = 0;
        int end = 0;
        for (int index : indexes) {
            if (meetings[index][0] > end) {
                result += meetings[index][0] - end - 1;
            }

            end = max(end, meetings[index][1]);
        }

        if (days > end) {
            result += days - end;
        }

        return result;
    }
};
