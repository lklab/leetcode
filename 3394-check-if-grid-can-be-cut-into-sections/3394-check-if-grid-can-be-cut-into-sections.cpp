class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<int> indices(rectangles.size());
        int end = 0;
        int count = 0;

        // horizontal
        for (int i = 0; i < rectangles.size(); ++i) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return rectangles[a][1] < rectangles[b][1];
        });

        end = rectangles[indices[0]][3];
        count = 0;
        for (int i = 1; i < indices.size(); ++i) {
            if (rectangles[indices[i]][1] >= end) {
                ++count;
                if (count == 2) {
                    return true;
                }
            }

            end = max(end, rectangles[indices[i]][3]);
        }

        // vertical
        for (int i = 0; i < rectangles.size(); ++i) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return rectangles[a][0] < rectangles[b][0];
        });

        end = rectangles[indices[0]][2];
        count = 0;
        for (int i = 1; i < indices.size(); ++i) {
            if (rectangles[indices[i]][0] >= end) {
                ++count;
                if (count == 2) {
                    return true;
                }
            }

            end = max(end, rectangles[indices[i]][2]);
        }

        return false;
    }
};
