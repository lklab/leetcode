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
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        queue<TreeNode*> q;
        stack<int> s;

        q.push(root);
        int count = 1;

        while (!q.empty())
        {
            // for even level
            for (int i = 0; i < count; ++i)
            {
                TreeNode* node = q.front();
                q.pop();

                if (node -> left != nullptr)
                {
                    q.push(node -> left);
                    q.push(node -> right);
                }
            }

            count = q.size();

            // for odd level
            for (int i = 0; i < count; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                s.push(node -> val);
                q.push(node);
            }

            for (int i = 0; i < count; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                node -> val = s.top();
                s.pop();

                if (node -> left != nullptr)
                {
                    q.push(node -> left);
                    q.push(node -> right);
                }
            }

            count = q.size();
        }

        return root;
    }
};
