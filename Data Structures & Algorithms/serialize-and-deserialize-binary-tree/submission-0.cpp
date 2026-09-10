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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string result = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currSize = q.size();
            for (int i = 0; i < currSize; i++) {
                TreeNode* curr = q.front(); q.pop();
                if (curr) {
                    result += to_string(curr->val) + ",";
                    q.push(curr->left);
                    q.push(curr->right);
                } else {
                    result += to_string(1001) + ",";
                }
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        vector<int> vals;
        string curr = "";
        for (char c : data) {
            if (c == ',') {
                vals.push_back(stoi(curr));
                curr = "";
            } else {
                curr += c;
            }
        }

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(vals[0]);
        q.push(root);
        int i = 1;
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (i < vals.size() && vals[i] != 1001) {
                TreeNode* left = new TreeNode(vals[i]);
                curr->left = left;
                q.push(left);
            }
            if (i + 1 < vals.size() && vals[i + 1] != 1001) {
                TreeNode* right = new TreeNode(vals[i + 1]);
                curr->right = right;
                q.push(right);
            }
            i += 2;
        }
        return root;
    }
};
