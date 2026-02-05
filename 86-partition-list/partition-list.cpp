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
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes for less and greater lists
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);

        // Pointers to build the two lists
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // Combine the two lists
        greater->next = nullptr;       // Important to avoid cycle
        less->next = greaterHead->next;

        return lessHead->next;
    }
};
