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
        if (!root) return nullptr;
        reverseOddLevelsHelper(root->left, root->right, 1);
        return root;
    }

private:
    void reverseOddLevelsHelper(TreeNode* left, TreeNode* right, int level)
    {
        if (!left || !right) return;

        // 홀수 레벨에서 값 스왑
        if (level % 2 == 1)
        {
            swap(left->val, right->val);
        }

        // 다음 레벨로 재귀 호출
        reverseOddLevelsHelper(left->left, right->right, level + 1);
        reverseOddLevelsHelper(left->right, right->left, level + 1);
    }
};
