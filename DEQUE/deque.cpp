#include<iostream>
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
class Deque{                                                        // Using doubly linked list.......
  
  
    public:
 
 
    Node *head=new Node(0);
    Node *tail=new Node(0);    

   Deque(){
        
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
   ~Deque(){
        delete head;
        delete tail;
   }

};

int main(){
    
    Deque d;
    d.insertfront(4);
    d.insertfront(5);
    d.insertfront(6);
    d.insertfront(7);
    d.display();
    d.insertBack(1);
    d.insertBack(2);
    d.insertBack(3);
    d.display();
    d.eraseback();
    d.display();
    d.erasefront();
    d.display();
    d.insertAfter(4,(d.head->next));
    d.display();
    d.deletion(d.head->next);
    d.display();
    
 
  return 0;

}