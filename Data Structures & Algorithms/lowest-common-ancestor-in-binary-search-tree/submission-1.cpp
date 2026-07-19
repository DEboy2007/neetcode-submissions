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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        int smaller = min(p->val, q->val);
        int bigger = max(p->val, q->val);
        while (true) {
            if (smaller <= curr->val && bigger >= curr->val) return curr;
            if (bigger < curr->val) curr = curr->left;
            if (smaller > curr->val) curr = curr->right;
        }
        
    }
};
