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
<<<<<<< HEAD



=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
class queue{
    public:

    node* front;    
    node* back;
    queue(){
       
        front=NULL;
        back=NULL;
    }
<<<<<<< HEAD

=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
    void push(int x){
        node* n=new node(x);
        if(front==NULL){
            back=n;
            front=n;
            return;
        }
        back->next=n;
<<<<<<< HEAD
        back=n;
    }

=======
        back=back->next;
    }
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
    void pop(){
        if(front==NULL){
            cout<<"Queue underfow"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;
        delete todelete;
    }

    int peek(){
        if(front==NULL){
            cout<<"Queue underfow"<<endl;
            return -1;
        }
        return (front->data);

    }

    bool empty(){
        if(front==NULL){          
            return true;
        }
        return false;
    }
};
<<<<<<< HEAD


=======
>>>>>>> 9f6b9d1aaec5af8be5bad6868396e39ce8d7b49e
int main(){


queue q;
q.push(4);
q.push(3);
q.push(2);
q.push(1);
cout<<q.peek()<<endl;
q.pop();
cout<<q.peek()<<endl;

return 0;
}