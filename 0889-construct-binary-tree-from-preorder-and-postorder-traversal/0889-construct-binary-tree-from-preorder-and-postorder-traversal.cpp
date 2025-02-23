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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        stack<TreeNode*> s;
        vector<bool> visited(n + 1, false);

        TreeNode* root = new TreeNode();
        root -> val = preorder[0];
        visited[preorder[0]] = true;
        s.push(root);

        int posti = 0;

        for (int i = 1; i < n; ++i) {
            TreeNode* current = s.top();
            TreeNode* next = new TreeNode();
            next -> val = preorder[i];

            // cout << "push: " << preorder[i] << endl;

            if (current -> left == nullptr) {
                current -> left = next;
            } else {
                current -> right = next;
            }

            s.push(next);
            visited[preorder[i]] = true;

            while (posti < n && visited[postorder[posti]]) {
                int target = postorder[posti];
                ++posti;

                while (true) {
                    TreeNode* top = s.top();
                    s.pop();

                    // cout << "pop: " << top -> val << endl;

                    if (top -> val == target) {
                        break;
                    }
                }
            }
        }

        return root;
    }
};
