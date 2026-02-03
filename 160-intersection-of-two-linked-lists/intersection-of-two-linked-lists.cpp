/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headA==NULL) return NULL;
        unordered_map<ListNode*, int> mp;

        ListNode* t1= headA;
        ListNode* t2= headB;

        while(t1!=NULL){
            mp[t1]=1;
            t1=t1->next;
        }
        while(t2!=NULL){
            if(mp.find(t2)!=mp.end()) return t2;
            t2=t2->next;
        }
        return NULL;



    }
};