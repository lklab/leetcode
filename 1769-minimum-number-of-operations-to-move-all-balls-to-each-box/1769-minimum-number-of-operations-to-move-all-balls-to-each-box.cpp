class Solution {
public:
    vector<int> minOperations(string boxes) {
        int lones = 0;
        int rones = 0;
        int ops = 0;

        for (int i = 1; i < boxes.size(); ++i) {
            if (boxes[i] == '1') {
                ++rones;
                ops += i;
            }
        }

        vector<int> result(boxes.size(), 0);
        result[0] = ops;

        for (int i = 1; i < boxes.size(); ++i) {
            if (boxes[i - 1] == '1') {
                ++lones;
            }
            ops += lones - rones;
            result[i] = ops;
            if (boxes[i] == '1') {
                --rones;
            }
        }

        return result;
    }
};
