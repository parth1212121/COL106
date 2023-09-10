#include<iostream>
using namespace std;

class Node{

    public:

    int data;
    Node* left;
    Node* right;
    Node* parent;

   Node(int val){
    data=val;
    left=NULL;
    right=NULL;
   } 
};

int height(Node* n){
    
    if(n==NULL){
        return -1;
    }
 
    return (max(height(n->left),height(n->right))+1);
    

}

bool is_balanced(Node* n){
    if(n==NULL){
        return true;
    }
    else{
        if(abs(height(n->left)-height(n->right))<=1){
            return true;
        }
        return false;
    }
}

void insert(Node* root,Node* v){                   
    
                                                  // Worst Case -->O(n).
                                                  // Average case--> O(log n)
    // Inserts node v into the BST.
    //Assumes that v->left and v->right are null
    // Assumes that v->key is not present in TREE.
    if(root==NULL){
        return ;
    }
    if(v->data<root->data){
        // Insert on the left side of the root.
        if(root->left==0){
            // We have found the right place to insert.
            root->left=v;
            v->parent=root;
        }
        else{
            insert(root->left,v);
        }
  }
  else{
     // Insert on the right side of the root.
        if(root->right==0){
            // We have found the right place to insert.
            root->right=v;
            v->parent=root;
        }
        else{
            insert(root->right,v);
        }
  }
}

void balance(Node* &root, Node* &n){


    Node* tmp=n;
    while(is_balanced(tmp->parent)){
        tmp=tmp->parent;
        if(tmp==root){
            return;
        }
    }
    
    // Case_1
   
     if((tmp->parent->left==tmp) && (n->data<tmp->data)){
        
       
        Node* a=tmp;
        Node* b=tmp->parent;
                                              // All connections.....

        a->parent=a->parent->parent;
        if((b!=root)){
        if(b->parent->left==b){
        b->parent->left=a;}
        else if(b->parent->right==b){
            b->parent->right=a;
        }
        }
        if(b==root){                         // Special case......
            root=a;
        }
        
        Node* t2=a->right;

        a->right=b;        
        b->parent=a;
       
        
        b->left=t2; 
   
        if(!(t2==NULL)){                         // Important!!!!
        t2->parent=b;}
       
    }

    // Case_2

    else if(tmp->parent->right==tmp && (n->data)>(tmp->data)){
            

            Node* a=tmp;
            Node* b=tmp->parent;

            a->parent=a->parent->parent;
            if(b!=root){
            if(b->parent->left==b){
            b->parent->left=a;}
            else if(b->parent->right==b){
                b->parent->right=a;
            }
            }

            if(b==root){
                root=a;
            }

            Node* t1=a->left;

            a->left=b;
            b->parent=a;

            b->right=t1;
            if(t1!=NULL){
                t1->parent=b;
            }
    }


    // Case_3

    else if(tmp->parent->left==tmp && n->data>tmp->data){
            
            Node* a=tmp;
            Node* b= tmp->parent;
            Node* d=tmp->right;
       

            d->parent=b->parent;
            
            if(b!=root){
            if(b->parent->left==b){
                d->parent->left=d;
            }
            else if(b->parent->right==b){
                d->parent->right=d;
            }}
            if(b==root){
                root=d;
            }

            a->parent=d;

            Node* t2a=d->left;
            Node* t2b=d->right;

            d->left=a;

            a->right=t2a;

            if(t2a!=NULL){
            t2a->parent=a;}
            
            b->parent=d;
            d->right=b;
            b->left=t2b;

            if(t2b!=NULL){
            t2b->parent=b;}
    
    }

    // Case_4

    else if(tmp->parent->right==tmp && n->data<tmp->data){
           
            Node* a=tmp;
            Node* b= tmp->parent;
            Node* d=tmp->left;
       
            d->parent=b->parent;
            if(b!=root){
            if(b->parent->left==b){
                d->parent->left=d;
            }
            else if(b->parent->right==b){

                d->parent->right=d;
            }}
            if(b==root){
                root=d;
            }

            a->parent=d;

            Node* t2a=d->left;
            Node* t2b=d->right;

            d->left=b;

            b->right=t2a;

            if(t2a!=NULL){
            t2a->parent=b;}
            
            b->parent=d;
            d->right=a;
            a->left=t2b;

            if(t2b!=NULL){
            t2b->parent=a;}    
    }
}



void insert_b(Node* &root,Node* &v){

    insert(root,v);
    balance(root,v);
    

}

int main(){  
    
    Node* root=new Node(15);
    Node* n10=new Node(10);
    Node* n2=new Node(2);
    Node* n12=new Node(12);
    Node* n11=new Node(11);
    Node* n14=new Node(14);
    Node* n24=new Node(24);
    Node* n20=new Node(20);
    
    Node* n29=new Node(29);
    
    insert(root,n10);
    insert(root,n2);
    insert(root,n12);
    
    insert(root,n11);
    insert(root,n24);
    
    insert(root,n20);
    insert(root,n29);

                                                     // Whatever node was added just....
    std::cout<<root->data<<endl;
    std::cout<<root->left->data<<endl;
    std::cout<<root->right->data<<endl;    
    std::cout<<root->left->right->data<<endl;
    std::cout<<root->left->left->data<<endl;
    std::cout<<root->right->left->data<<endl;
    std::cout<<root->right->right->data<<endl;
    
    return 0;
}