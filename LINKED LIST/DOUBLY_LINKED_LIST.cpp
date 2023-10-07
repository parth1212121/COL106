// See deque file there douby linked list is extensively used...


// ALSO FULLL IMPLEMENTATION WRITTEN IN NOTES......
#include<bits/stdc++.h>
using namespace std;

class Node{ 
    public:
        int val;
        Node* prev;
        Node* next;
     Node(int data){
        val=data;
        prev=NULL;
        next=NULL;

    }
};
class DLL{                                                        // Using doubly linked list.......
  
  
    public:
 
 
    Node *head=new Node(0);   // sentinal_head
    Node *tail=new Node(0);   // sentinal_tail

   DLL(){
        
         head->next=tail;
         tail->prev=head;
    }

    void insertfront(int val){        
        Node* n=new Node(val);
        head->next->prev=n;
        n->next=head->next;
        head->next=n;
        n->prev=head;   
        return;        
     }

     void insertBack(int val){
         Node* n=new Node(val);
         tail->prev->next=n;
         n->prev=tail->prev;
         n->next=tail;
         tail->prev=n;
     }

    
     void erasefront(){
         Node* todelete= head->next;
         head->next->next->prev=head;
         head->next=head->next->next;
         delete todelete;
     }

     void eraseback(){
         Node* todelete= tail->prev;
         tail->prev->prev->next=tail;
         tail->prev=tail->prev->prev;
        delete todelete;
     }

     void insertAfter(int val,Node*n){
        Node*k =new Node(val);
        n->next->prev=k;
        k->next=n->next;
        n->next=k;
        k->prev=n;        
     }

     void deletion(Node* n){
        Node* todelete=n;
        n->prev->next=n->next;
        n->next->prev=n->prev;
        delete todelete;
     }

     void display(){
         Node* curr=head->next;
        while(curr->next!=NULL){
             cout<<curr->val<<" ";
             curr=curr->next;
         }cout<<endl;
     }
   ~DLL(){
        delete head;
        delete tail;
   }

};