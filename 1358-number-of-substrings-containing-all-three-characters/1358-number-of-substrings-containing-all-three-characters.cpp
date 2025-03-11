class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int counts[3];

        int r = 0;
        while (r < n && (counts[0] == 0 || counts[1] == 0 || counts[2] == 0)) {
            ++counts[s[r] - 'a'];
            ++r;
        }

        if (counts[0] == 0 || counts[1] == 0 || counts[2] == 0) {
            return 0;
        }
        // cout << "r=" << r << " add=" << n - r + 1 << endl;
        int result = n - r + 1;

        int l = 0;
        while (true) {
            if (--counts[s[l] - 'a'] == 0) {
                // if (r == n) {
                //     return result;
                // }

                int target = s[l] - 'a';
                while (r < n && counts[target] == 0) {
                    ++counts[s[r] - 'a'];
                    ++r;
                }

                if (counts[target] > 0) {
                    // cout << "l=" << l << " r=" << r << " add=" << n - r + 1 << endl;
                    result += n - r + 1;
                } else {
                    return result;
                }

            } else {
                // cout << "l=" << l << " r=" << r << " add=" << n - r + 1 << endl;
                result += n - r + 1;
            }

            ++l;
        }

        return result;
    }
};
