#include<iostream>
using namespace std;
class Node{
       public:
       int val;
        Node* next;
        Node(int value,Node*n=NULL){
            val=value;
            next=n;
}
};
void insertAthead(int data, Node* &head){
    Node* newnode=new Node(data);
    if(head==NULL){
        head=newnode;
    }
    else{
            newnode->next=head;
            head=newnode;
   }   
}
<<<<<<< HEAD

=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
void insertAfter(Node* &n,int data){
    Node* newnode=new Node(data);
    if(n!=NULL){
            newnode->next=n->next;
            n->next=newnode;
    }
    else{
        return ;
}}
<<<<<<< HEAD

=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
void insertAtend(int data,Node* &head){
    if(head==NULL || head->next==NULL){
        insertAthead(data,head);
    }
    else{
    Node* newnode=new Node(data);
    Node* currptr=head;
    while(currptr->next!=NULL){
        currptr=currptr->next;
    }
    insertAfter(currptr,data);
    }
}
// Deletion in  a linked list....

void deletefromhead(Node* &head){

    if(head==NULL){
        return ;
    }
    else{
        Node* temp=head;
        head=head->next;
        delete temp;
    }
}

void deleteafternode(Node* &n){
    if(n==NULL || n->next==NULL){
        return;
    }
    else{

        Node* temp=n->next;
        n->next=n->next->next;
        delete temp;
    }
}

void deletefromend(Node* &head){
    if(head==NULL){
        return;
    }
    else if(head->next==NULL){
        return;
    }
    else{
        Node* cur=head;
        while(cur->next->next!=NULL){
            cur=cur->next;
        }
        deleteafternode(cur);
    }
}


void display(Node* head){
    Node* curptr=head;
    while(curptr!=NULL){
        cout<<curptr->val<<" ";
        curptr=curptr->next;
    }cout<<endl;
}

int main(){
    Node* head=NULL;
    insertAthead(5,head);
    //display(head);
    insertAthead(6,head);
    insertAthead(8,head);
    insertAfter(head,7);
    insertAtend(9,head);
    deletefromend(head);

    deletefromhead(head);
    deleteafternode(head);
    display(head);


return 0;
}

