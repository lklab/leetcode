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
class FindElements {
private:
    unordered_set<int> vals;

    void dfs(TreeNode* node) {
        int val = node -> val;
        vals.insert(val);

        if (node -> left != nullptr) {
            node -> left -> val = 2 * val + 1;
            dfs(node -> left);
        }
        if (node -> right != nullptr) {
            node -> right -> val = 2 * val + 2;
            dfs(node -> right);
        }
    }

public:
    FindElements(TreeNode* root) {
        root -> val = 0;
        dfs(root);
    }
    
    bool find(int target) {
        return vals.find(target) != vals.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */