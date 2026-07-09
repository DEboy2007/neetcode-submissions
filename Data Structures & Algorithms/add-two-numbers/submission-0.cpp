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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // go from left to right, add both and send carryover
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carryover = 0;
        ListNode* head = new ListNode(0);
        ListNode* result = head;
        while (p1 || p2) {
            int curr = 0;
            if (p1) {
                curr += p1->val;
                p1 = p1->next;
            }
            if (p2) {
                curr += p2->val;
                p2 = p2->next;
            }
            curr += carryover;
            carryover = curr / 10;
            ListNode* ts = new ListNode(curr % 10);
            result->next = ts;
            result = ts;
        }
        while (carryover != 0) {
            ListNode* ts = new ListNode(carryover % 10);
            result->next = ts;
            result = ts;
            carryover /= 10;
        }
        return head->next;
        
    }
};
