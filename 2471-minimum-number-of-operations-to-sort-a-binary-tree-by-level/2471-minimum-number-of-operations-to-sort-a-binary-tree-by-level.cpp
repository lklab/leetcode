/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    int minimumSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> valueIndex(n);
        for (int i = 0; i < n; ++i) {
            valueIndex[i] = {arr[i], i};
        }

        // 값을 기준으로 정렬
        sort(valueIndex.begin(), valueIndex.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            // 이미 방문했거나 제자리에 있는 경우
            if (visited[i] || valueIndex[i].second == i) {
                continue;
            }

            // 사이클 탐색
            int cycleSize = 0;
            int current = i;

            while (!visited[current]) {
                visited[current] = true;
                current = valueIndex[current].second;
                ++cycleSize;
            }

            // 사이클 크기가 n이면 n-1번의 스왑 필요
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }
public:
    int minimumOperations(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        vector<int> arr;

        int result = 0;

        while (!q.empty())
        {
            if (count == 0)
            {
                count = q.size();
                result += minimumSwaps(arr);
                arr.clear();
            }

            TreeNode* node = q.front();
            q.pop();
            --count;

            if (node -> left != nullptr)
            {
                q.push(node -> left);
                arr.push_back(node -> left -> val);
            }
            if (node -> right != nullptr)
            {
                q.push(node -> right);
                arr.push_back(node -> right -> val);
            }
        }

        return result;
    }
};
