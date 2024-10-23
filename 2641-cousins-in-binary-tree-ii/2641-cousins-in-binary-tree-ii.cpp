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
    TreeNode* replaceValueInTree(TreeNode* root)
    {
        root -> val = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSum = 0;
            int count = q.size();
            TreeNode* nodes[count];
            int childSums[count];

            for (int i = 0; i < count; ++i)
            {
                TreeNode* node = q.front();
                TreeNode* left = node -> left;
                TreeNode* right = node -> right;
                q.pop();

                int childSum = 0;

                if (left != nullptr)
                {
                    levelSum += left -> val;
                    childSum += left -> val;
                    q.push(left);
                }
                if (right != nullptr)
                {
                    levelSum += right -> val;
                    childSum += right -> val;
                    q.push(right);
                }

                nodes[i] = node;
                childSums[i] = childSum;
            }

            for (int i = 0; i < count; ++i)
            {
                TreeNode* node = nodes[i];
                TreeNode* left = node -> left;
                TreeNode* right = node -> right;

                int val = levelSum - childSums[i];

                if (left != nullptr)
                {
                    left -> val = val;
                }
                if (right != nullptr)
                {
                    right -> val = val;
                }
            }
        }

        return root;
    }
};
