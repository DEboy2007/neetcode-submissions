/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class CompareListNode {
    public:
    bool operator()(const ListNode* a, const ListNode* b) {
        // greater value -> lower priority
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> pq;
        for (ListNode* n : lists) {
            pq.push(n);
        }

        ListNode* prev = nullptr;
        ListNode* head = nullptr;
        while (!pq.empty()) {
            ListNode* top = pq.top(); pq.pop();
            if (prev) {
                prev->next = top;
            } else {
                head = top;
            }
            prev = top;
            if (top->next) pq.push(top->next);
        }

        return head;
    }
};
