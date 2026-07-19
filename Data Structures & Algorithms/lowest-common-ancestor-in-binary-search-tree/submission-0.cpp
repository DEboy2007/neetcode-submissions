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
        // level order BFS, track height of each node and the nodes in each level (with vector)
        // track parent of each node?
        // track children of each node
        deque<TreeNode*> dq;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, int> level;
        dq.push_back(root);
        parent[root] = nullptr;
        int currLevel = 0;
        TreeNode* endOfCurrLevel = dq.back();
        while (!dq.empty()) {
            TreeNode* curr = dq.front(); dq.pop_front();
            if (!curr) continue;
            level[curr] = currLevel;
            if (curr->left) {
                parent[curr->left] = curr;
                dq.push_back(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                dq.push_back(curr->right);
            }
            if (curr == endOfCurrLevel) {
                endOfCurrLevel = dq.back();
                currLevel++;
            }
        }

        // trace upwards through parents for higher level (p/q) until you get to lower level
        // then go up until pointers meet
        TreeNode* lowerPointer = (level[p] > level[q]) ? p : q;
        TreeNode* upperPointer = (level[p] > level[q]) ? q : p;
        while (lowerPointer && level[lowerPointer] > level[upperPointer]) {
            lowerPointer = parent[lowerPointer];
        }
        while (lowerPointer != upperPointer) {
            lowerPointer = parent[lowerPointer];
            upperPointer = parent[upperPointer];
        }
        return lowerPointer;
    }
};
