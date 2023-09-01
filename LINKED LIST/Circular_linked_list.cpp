#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
    node(int val){
        data=val;
        next=NULL;
    }  
};
void insertAthead(node* &head,int val){

    node* n=new node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
void insertAttail(node* &head,int val){

    if(head==NULL){
        insertAthead(head,val);
        return;
    }
    else{
    node* n=new node(val);
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    }
}
/// Deletion...
void deleteAthead(node* &head){
    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node* todelete=head;
    temp->next=head->next;
    head=head->next;
    delete todelete;
}
void deletion(node* &head,int pos){
    if(pos==1){
        deleteAthead(head);
        return;
    }
    else{
            node*temp=head;
            int count=1;
            while(count!=(pos-1)){
                temp=temp->next;
                count++;
            }
            node* todelete=temp->next;
            temp->next =temp->next->next;
            delete todelete;
    }
    }
void display(node* head){

        node* temp= head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;

}
bool check(node* &head){
        if(head==NULL){
            return 0;
        }

        node* curr=head->next;
        bool ans=false;
        while(curr->next!=head){
            if(curr->next==NULL){
                break;
            }
            curr=curr->next;
        }
        if(curr->next==head){
            ans=true;
        }
        return ans;  
    }
int main(){

node* head=NULL;
insertAttail(head,5);
insertAttail(head,7);
//display(head);
insertAttail(head,8);
insertAttail(head,9);
insertAthead(head,3);
//display(head);
deletion(head,1);
//display(head);
cout<<check(head)<<endl;

}