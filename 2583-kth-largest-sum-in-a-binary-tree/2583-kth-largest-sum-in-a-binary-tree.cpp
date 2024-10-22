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
public:
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        vector<long long> levelSums;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty())
        {
            long long sum = 0;
            int count = q.size();

            for (int i = 0; i < count; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                sum += node -> val;

                if (node -> left != nullptr)
                {
                    q.push(node -> left);
                }
                if (node -> right != nullptr)
                {
                    q.push(node -> right);
                }
            }

            levelSums.push_back(sum);
        }

        sort(levelSums.begin(), levelSums.end(), greater<long long>());

        if (levelSums.size() < k)
        {
            return -1;
        }

        return levelSums[k - 1];
    }
};
