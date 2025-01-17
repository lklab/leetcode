class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int current = derived[0];

        for (int i = 1; i < derived.size(); ++i) {
            current ^= derived[i];
        }

        return current == 0;
    }
};
