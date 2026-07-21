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
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* revhalf=reverseList(slow);

        ListNode* temp1=head;
        ListNode* temp2=revhalf;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val!=temp2->val) return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }


    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* newhead =reverseList(head->next);
        ListNode* temp=head->next;
        head->next=temp->next;
        temp->next=head;

        return newhead;
        
    }
};