/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp= head;
        unordered_map<Node* , Node*> mp;
        while(temp!=NULL){
            mp[temp]=new Node(temp->val);
            temp=temp->next;
        }

        temp=head;
        while(temp!=NULL){
            mp[temp]->next= mp[temp->next];
            mp[temp]->random= mp[temp->random];
            temp=temp->next;
        }
        return mp[head];

        // Node* dhead=new Node(-1);
        // Node* t1=dhead;
        // Node* temp= head;

        // vector <Node*> rand;
        // unordered_map<Node* , Node*> mp;
        // while(temp!=NULL){
        //     int data= temp->val;
        //     rand.push_back(temp->random);
        //     Node* t2=new Node(data);
        //     mp[temp]=t2;
        //     t1->next=t2;
        //     t1=t1->next;
        //     temp=temp->next;
        // }

        // t1=dhead->next;
        // int i=0;
        // while(t1!=NULL){
        //     if(rand[i]!=NULL){
        //         t1->random= mp[rand[i]];
        //     }else{
        //         t1->random=NULL;
        //     }
        //     t1=t1->next;
        //     i++;
        // }

        // return dhead->next;
        
        
    }
};