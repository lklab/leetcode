class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diff(s.size() + 1, 0);

        for (const auto& shift : shifts) {
            if (shift[2] == 0) {
                --diff[shift[0]];
                ++diff[shift[1] + 1];
            } else {
                ++diff[shift[0]];
                --diff[shift[1] + 1];
            }
        }

        int curr = 0;
        for (int i = 0; i < s.size(); ++i) {
            curr += diff[i];
            curr %= 26;

            int c = (s[i] - 'a' + curr) % 26;
            if (c < 0) {
                c += 26;
            }
            s[i] = c + 'a';
        }

        return s;
    }
};
