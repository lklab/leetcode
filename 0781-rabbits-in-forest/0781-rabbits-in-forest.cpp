class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> counts(1000, 0);
        int result = 0;

        for (int answer : answers) {
            if (counts[answer] == 0) {
                result += answer + 1;
                counts[answer] = answer;
            } else {
                --counts[answer];
            }
        }

        return result;
    }
};
