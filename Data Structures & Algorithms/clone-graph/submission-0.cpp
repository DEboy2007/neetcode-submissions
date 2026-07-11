/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // queue (BFS)
        // make new node for original node, push to queue
        // pop front of queue: make a new node for every neighbor unless already seen (in that case link)
        // push all the new nodes created to queue
        if (!node) return node;
        queue<Node*> q;
        unordered_map<Node*, Node*> oldToNew;

        Node* res = new Node(node->val, node->neighbors);
        oldToNew[node] = res;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            for (int i = 0; i < curr->neighbors.size(); i++) {
                Node* n = curr->neighbors[i];
                Node* newN = nullptr;
                if (oldToNew.contains(n)) {
                    newN = oldToNew[n];
                } else {
                    newN = new Node(n->val, n->neighbors);
                    oldToNew[n] = newN;
                    q.push(n);
                }
                curr->neighbors[i] = newN;
            }
        }
        return res;
    }
};
