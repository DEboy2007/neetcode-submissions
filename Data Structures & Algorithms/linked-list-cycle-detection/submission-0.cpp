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
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        while (ptr1 && ptr2 && ptr2->next) {
            if (ptr1 == ptr2) return true;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        return false;
        
    }
};
