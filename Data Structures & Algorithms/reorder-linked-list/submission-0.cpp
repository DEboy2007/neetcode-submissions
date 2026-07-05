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
    void reorderList(ListNode* head) {
        // given 0 1 2 3 4 5 6
        // reverse 4 5 6 -> 6 5 4
        // interlace 0 1 2 3
        // result: 0 6 1 5 2 4 3
        int len = 0;
        ListNode* halfway = head;
        ListNode* speedy = head;
        while (halfway && speedy && speedy->next) {
            speedy = speedy->next->next;
            halfway = halfway->next;
        }
        // reverse
        ListNode* prev = nullptr;
        ListNode* curr = halfway;
        ListNode* next = halfway->next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // list 1: [head -> halfway)
        // list 2: [prev -> halfway]
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p1 && p2 && p2->next) {
            ListNode* temp = p1->next;
            p1->next = p2;
            p1 = temp;
            ListNode* temp2 = p2->next;
            p2->next = p1;
            p2 = temp2;
        }
    }
};
