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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int sz = 0;
        while (curr) {
            curr = curr->next;
            sz++;
        }
        ListNode* prevSegmentStart = nullptr;
        ListNode* resHead = nullptr;
        curr = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < sz / k; i++) {
            ListNode* start = curr;
            prev = nullptr;
            for (int j = 0; j < k; j++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            if (prevSegmentStart) {
                prevSegmentStart->next = prev;
            } else {
                resHead = prev;
            }
            prevSegmentStart = start;
        }
        if (sz % k != 0) {
            if (prevSegmentStart) prevSegmentStart->next = curr;
        }
        return resHead;
    }
};
