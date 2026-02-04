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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL ||k==0) return head;
        ListNode* temp= head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k%n==0) return head;

        ListNode* head_second_half=head;
        ListNode* second_half=head_second_half;
        for(int i=1;i<n-k;i++){
            second_half=second_half->next;
        }
        ListNode* head_first_half=second_half->next;
        ListNode* first_half=head_first_half;
        second_half->next=NULL;
        
        for(int j=1;j<k;j++){
            first_half=first_half->next;
        }
        first_half->next=head_second_half;

        return head_first_half;
        
    }
};