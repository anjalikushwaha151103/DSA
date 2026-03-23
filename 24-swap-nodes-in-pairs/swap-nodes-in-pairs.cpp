class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node helps handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev to next pair
            prev = first;
        }

        return dummy->next;
    }
};