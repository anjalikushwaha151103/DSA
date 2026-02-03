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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if(l1==NULL && l2==NULL) return NULL;
        // if(l1==NULL) return l2;
        // if(l2==NULL) return l1;

        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* h_ans=new ListNode(-1);
        ListNode* ans= h_ans;
        int carry=0;

        while(t1!=NULL || t2!=NULL){
            int sum=carry;
            if(t1!=NULL){
                sum+= t1->val;
                t1=t1->next;
            }
            
            if(t2!=NULL){
                sum+= t2->val;
                t2=t2->next;
            }


            if(sum<10){
                carry=0;
            }else{
                sum=sum-10;
                carry=1;
            }
            
            
            ans->next= new ListNode(sum);
            ans=ans->next;
        }
        if(carry==1){
            ans->next= new ListNode(1);
            ans=ans->next;
        }
        return h_ans->next;
    }
};