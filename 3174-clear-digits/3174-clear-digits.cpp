class Solution {
public:
    string clearDigits(string s) {
        deque<char> dq;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                dq.pop_back();
            } else {
                dq.push_back(c);
            }
        }

        string result;

        for (char c : dq) {
            result.push_back(c);
        }

        return result;
    }
};
