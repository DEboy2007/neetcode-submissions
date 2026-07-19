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
    int goodNodes(TreeNode* root) {
        int counter = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, -101});
        while (!q.empty()) {
            auto [curr, currMax] = q.front(); q.pop();
            if (curr->val >= currMax) counter++;
            currMax = max(currMax, curr->val);
            if (curr->left) q.push({curr->left, currMax});
            if (curr->right) q.push({curr->right, currMax});
        }
        return counter;
        
    }
};
