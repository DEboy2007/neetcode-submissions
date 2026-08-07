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
    int mx = INT_MIN;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);
        mx = max(mx, l + r + root->val);
        return max(l + root->val, r + root->val);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mx;
    }
};
