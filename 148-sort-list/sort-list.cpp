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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=middleNode(head);
        ListNode* midnext=mid->next;
        mid->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(midnext);
        ListNode* anshead = merge(left,right);
        return anshead;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* fast= head;
        ListNode* slow= head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;   
    }

    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;

        ListNode* t1=left;
        ListNode* t2=right;
        

        while(t1!=NULL && t2!=NULL){
            if(t1->val < t2-> val){
                tail->next=t1;
                t1=t1->next;
            }else{
                tail->next=t2;
                t2=t2->next;
            }
            tail=tail->next;
        }

        if(t1==NULL){
            while(t2!=NULL){
                tail->next=t2;
                t2=t2->next;
                tail=tail->next;
            }
        }
        
        if(t2==NULL){
            while(t1!=NULL){
                tail->next=t1;
                t1=t1->next;
                tail=tail->next;
            }
        }
        
        return dummy->next;
    }

};