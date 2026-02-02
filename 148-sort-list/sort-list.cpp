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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }


    ListNode* merge(ListNode* lh, ListNode* rh){
        ListNode* t1=lh;
        ListNode* t2=rh;
        ListNode* dnode= new ListNode(-1);
        ListNode*temp=dnode;

        while(t1!=NULL && t2!=NULL){
            if(t1->val < t2->val){
                temp->next=t1;
                temp=temp->next;
                t1=t1->next;
            }else{
                temp->next=t2;
                temp=temp->next;
                t2=t2->next;
            }
        }
        if(t1){
            temp->next=t1;
        }
        if(t2){
            temp->next=t2;
        }
        return dnode->next;
    }


    ListNode* sortList(ListNode* head) {
        if(head==NULL ||head->next==NULL) return head;
        ListNode* middle= middleNode(head);
        ListNode* lh=head;
        ListNode* rh=middle->next;
        middle->next=NULL;

        lh=sortList(lh);
        rh=sortList(rh);
        return merge(lh,rh);
        
    }
};