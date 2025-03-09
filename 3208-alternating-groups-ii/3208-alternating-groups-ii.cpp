class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int prefix = -1;

        // find first same color
        for (int i = 0; i < n - 1; ++i) {
            if (colors[i] == colors[i + 1]) {
                prefix = i + 1;
                break;
            }
        }

        if (prefix == -1) {
            if (colors[0] != colors[n - 1]) {
                return n; // k == n ? 1 : n;
            } else {
                return n - k + 1;
            }
        }

        int start = prefix;
        int index = prefix;
        int result = 0;

        // cout << "prefix: " << prefix << endl;

        while (index < n - 1) {
            while (index < n - 1 && colors[index] == colors[index + 1]) {
                ++index;
            }

            start = index;
            // cout << "start: " << start << endl;

            while (index < n - 1 && colors[index] != colors[index + 1]) {
                ++index;
            }
            // cout << "index: " << index << endl;

            if (index < n - 1) {
                result += max(0, index - start - k + 2);
            }
        }

        if (colors[0] != colors[n - 1]) {
            int count = prefix + index - start + 1;
            result += max(0, count - k + 1);
        } else {
            result += max(0, prefix - k + 1);
            result += max(0, index - start - k + 2);
        }

        return result;
    }
};
