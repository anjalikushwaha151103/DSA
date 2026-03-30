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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Step 1: Push first node of each list
        for (auto node : lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }

        // Dummy node to build result
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Step 2: Process heap
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            temp->next = smallest;
            temp = temp->next;

            if (smallest->next != NULL) {
                pq.push(smallest->next);
            }
        }
        return dummy->next;
    }
};