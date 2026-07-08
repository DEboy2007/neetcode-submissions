/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        Node* resHead = new Node(head->val);
        oldToNew[head] = resHead;
        Node* curr = head->next;
        Node* prev = resHead;
        while (curr) {
            Node* ts = new Node(curr->val);
            oldToNew[curr] = ts;
            prev->next = ts;
            prev = ts;
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            oldToNew[curr]->random = oldToNew[curr->random]; 
            curr = curr->next;
        }

        return resHead;
    }
};
