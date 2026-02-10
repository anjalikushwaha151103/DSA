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
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;

        while(true){
            ListNode* start=prev->next;
            ListNode* curr=start;
            ListNode* knode=findk(curr,k);
            if(knode){
                curr=knode->next;
                knode->next=NULL;
            }else{
                break;
            }
            ListNode* newhead=reverse(start);
            prev->next=newhead;
            start->next=curr;
            prev=start;
        }
        return dummy->next;
    }
    ListNode*  reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* node=head;
        while(node!=NULL){
            ListNode* front=node->next;
            node->next=prev;
            prev=node;
            node=front;
        }  
        return prev;  
    }

    ListNode* findk(ListNode* curr, int k){
        ListNode* temp=curr;
        for(int i=0;i<k-1;i++){
            if(temp==NULL) return NULL;
            else temp=temp->next;
        }
        return temp;
        
    }
};