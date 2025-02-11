class Solution {
public:
    string removeOccurrences(string s, string part) {
        deque<char> dq;
        int n = part.size();

        for (char c : s) {
            dq.push_back(c);

            bool match = true;
            int offset = dq.size() - n;
            for (int i = 0; i < n; ++i) {
                if (offset < 0 || dq[i + offset] != part[i]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                for (int i = 0; i < n; ++i) {
                    dq.pop_back();
                }
            }
        }

        string result;
        for (char c : dq) {
            result.push_back(c);
        }

        return result;
    }
};
