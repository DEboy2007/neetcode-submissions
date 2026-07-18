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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top(); st.pop();
            if (!curr) continue;
            if (curr->val == subRoot->val && isEqual(curr, subRoot)) return true; 
            st.push(curr->left);
            st.push(curr->right);
        }
        return false;
    }

    bool isEqual(TreeNode* r1, TreeNode* r2) {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({r1, r2});
        while (!st.empty()) {
            auto [n1, n2] = st.top(); st.pop();
            if (!n1 && !n2) continue;
            if (!n1 || !n2) return false;
            if (n1->val != n2->val) return false;
            st.push({n1->left, n2->left});
            st.push({n1->right, n2->right});
        }
        return true;
    }
};
