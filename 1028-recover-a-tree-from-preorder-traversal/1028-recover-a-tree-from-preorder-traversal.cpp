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
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        TreeNode* root = new TreeNode();
        int val = 0;
        int index = 0;

        while (index < n && traversal[index] != '-') {
            val *= 10;
            val += traversal[index] - '0';
            ++index;
        }
        root -> val = val;
        stack<TreeNode*> s;
        s.push(root);
        int depth = 1;

        for (int i = index; i < n; ++i) {
            if (traversal[i] == '-') {
                ++depth;

            } else {
                val = 0;
                index = i;

                while (index < n && traversal[index] != '-') {
                    val *= 10;
                    val += traversal[index] - '0';
                    ++index;
                }

                TreeNode* node = new TreeNode();
                node -> val = val;
                cout << node -> val << endl;

                if (s.size() >= depth) {
                    int removes = s.size() - depth;
                    for (int j = 0; j <= removes; ++j) {
                        s.pop();
                    }
                }

                if (s.top() -> left == nullptr) {
                    s.top() -> left = node;
                } else {
                    s.top() -> right = node;
                }

                s.push(node);
                depth = 1;
                i = index - 1;
            }
        }

        return root;
    }
};
