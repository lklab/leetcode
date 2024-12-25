/**
 * Definition for a binary tree node.
 * struct TreeNode{
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
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        int largest = -2147483648;

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            --count;

            largest = max(largest, node -> val);

            if (node -> left != nullptr)
            {
                q.push(node -> left);
            }
            if (node -> right != nullptr)
            {
                q.push(node -> right);
            }

            if (count == 0)
            {
                result.push_back(largest);
                count = q.size();
                largest = -2147483648;
            }
        }

        return result;
    }
};
