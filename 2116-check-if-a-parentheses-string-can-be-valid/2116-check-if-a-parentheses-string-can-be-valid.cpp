class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 == 1) {
            return false;
        }

        int pmax = 0;
        int pmin = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (locked[i] == '0') {
                ++pmax;
                if (pmin == 0) {
                    pmin = 1;
                } else {
                    --pmin;
                }
            } else if (s[i] == '(') {
                ++pmax;
                ++pmin;
            } else {
                --pmax;
                if (pmin == 0) {
                    pmin = 1;
                } else {
                    --pmin;
                }

                if (pmax < 0) {
                    return false;
                }
            }
        }

        return pmin == 0;
    }
};
