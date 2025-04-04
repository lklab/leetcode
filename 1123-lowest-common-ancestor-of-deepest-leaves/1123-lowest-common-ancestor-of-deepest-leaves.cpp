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
class Solution {
private:
    int postorder(TreeNode* node, int depth) {
        int leftDepth = depth;
        int rightDepth = depth;

        if (node -> left != nullptr) {
            leftDepth = postorder(node -> left, depth + 1);
        }

        if (node -> right != nullptr) {
            rightDepth = postorder(node -> right, depth + 1);
        }

        if (leftDepth == rightDepth && leftDepth >= maxDepth) {
            maxDepth = leftDepth;
            result = node;
        }

        return max(leftDepth, rightDepth);
    }

    int maxDepth = 0;
    TreeNode* result = nullptr;

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        postorder(root, 0);
        return result;
    }
};
