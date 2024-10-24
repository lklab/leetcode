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
    bool flipEquiv(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == nullptr || root2 == nullptr)
        {
            return root1 == nullptr && root2 == nullptr;
        }

        if (root1 -> val != root2 -> val)
        {
            return false;
        }

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(root1);
        q2.push(root2);

        while (!q1.empty())
        {
            int count = q1.size();
            unordered_map<int, pair<int, int>> map;

            for (int i = 0; i < count; ++i)
            {
                TreeNode* node = q1.front();
                TreeNode* left = node -> left;
                TreeNode* right = node -> right;
                q1.pop();

                pair<int, int> vals1;

                if (left != nullptr)
                {
                    vals1.first = left -> val;
                    q1.push(left);
                }
                else
                {
                    vals1.first = -1;
                }
                if (right != nullptr)
                {
                    vals1.second = right -> val;
                    q1.push(right);
                }
                else
                {
                    vals1.second = -1;
                }

                map[node -> val] = vals1;
            }

            for (int i = 0; i < count; ++i)
            {
                TreeNode* node = q2.front();
                TreeNode* left = node -> left;
                TreeNode* right = node -> right;
                q2.pop();

                int vals2[2] = { -1, -1 };

                if (left != nullptr)
                {
                    vals2[0] = left -> val;
                    q2.push(left);
                }
                if (right != nullptr)
                {
                    vals2[1] = right -> val;
                    q2.push(right);
                }

                pair<int, int> vals1 = map[node -> val];
                map.erase(node -> val);

                if ((vals1.first != vals2[0] || vals1.second != vals2[1]) &&
                    (vals1.first != vals2[1] || vals1.second != vals2[0]))
                {
                    return false;
                }
            }
        }

        return true;
    }
};
