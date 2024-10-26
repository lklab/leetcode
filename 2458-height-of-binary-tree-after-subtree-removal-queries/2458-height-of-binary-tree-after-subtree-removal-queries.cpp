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
private:
    int countTree(TreeNode* tree)
    {
        int count = 1;
        if (tree -> left != nullptr)
        {
            count += countTree(tree -> left);
        }
        if (tree -> right != nullptr)
        {
            count += countTree(tree -> right);
        }
        return count;
    }

    int setupTree(TreeNode* tree, int heightArr[], TreeNode* parentArr[])
    {
        TreeNode* left = tree -> left;
        TreeNode* right = tree -> right;
        int height = 0;

        if (left != nullptr)
        {
            parentArr[left -> val] = tree;
            height = max(setupTree(left, heightArr, parentArr), height);
        }
        if (right != nullptr)
        {
            parentArr[right -> val] = tree;
            height = max(setupTree(right, heightArr, parentArr), height);
        }

        ++height;
        heightArr[tree -> val] = height;
        return height;
    }

    void test(int arr[])
    {
        arr[1] = 10;
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) 
    {
        int n = countTree(root);
        int heightArr[n + 1];
        TreeNode* parentArr[n + 1];
        parentArr[root -> val] = nullptr;

        setupTree(root, heightArr, parentArr);

        unordered_map<int, int> known;

        for (int i = 0; i < queries.size(); ++i)
        {
            int query = queries[i];

            if(known.find(query) != known.end())
            {
                queries[i] = known[query];
            }
            else
            {
                TreeNode* current = parentArr[query];
                int height = 0;
                int prev = query;

                while (current != nullptr)
                {
                    TreeNode* other = nullptr;

                    if (current -> left != nullptr && current -> left -> val != prev)
                    {
                        other = current -> left;
                    }
                    else if (current -> right != nullptr && current -> right -> val != prev)
                    {
                        other = current -> right;
                    }

                    if (other != nullptr)
                    {
                        height = max(heightArr[other -> val], height);
                    }

                    ++height;
                    prev = current -> val;
                    current = parentArr[current -> val];
                }

                --height;
                queries[i] = height;
                known[query] = height;
            }
        }

        return queries;
    }
};
