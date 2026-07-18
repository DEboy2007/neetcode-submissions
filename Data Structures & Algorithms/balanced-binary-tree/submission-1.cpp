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
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }

    pair<int, bool> dfs(TreeNode* root) {
        if (!root) return {0, true};
        pair<int, bool> l = dfs(root->left);
        pair<int, bool> r = dfs(root->right);
        bool balanced = l.second && r.second && abs(l.first - r.first) < 2;
        int height = 1 + max(l.first, r.first);
        return {height, balanced};
    }
};