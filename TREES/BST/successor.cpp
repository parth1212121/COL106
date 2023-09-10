#include<iostream>
using namespace std;
class Node{           // Succesor of u is the node with the smallest bigger value than u->data.

    public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

   Node(int val){      
    data=val;
    left=NULL;
    right=NULL;
    parent=NULL;

   } 
}; 

Node* find_min(Node* root){
    if(root==NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
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

Node* Successor(Node* u){                                                 // O(h) ... 
    if(u->right!=NULL){
        return find_min(u->right);
    }
    else{
        while((u->parent!=NULL && (u==u->parent->right))){
            u=u->parent;
        }
        return u->parent;
    }
}


int main(){  

    Node* root= new Node(4);   
    Node* n1= new Node(2);      
    Node* n2= new Node(6);
    Node* n3= new Node(1);
    Node* n4= new Node(3);
    Node* n5= new Node(5);      // Worst case running time of N insaert operations-->O(nsq.)
    Node* n6= new Node(7);
    insert(root,n1);
    insert(root,n2);
    insert(root,n3);
    insert(root,n4);
    insert(root,n5);
    insert(root,n6);
    cout<<Successor(root->left->left)->data<<endl;

/// By definintion u is also a ancesstor of u.......


    //cout<<root->left->right->data<<endl;
        
                                                                         //    4
    // root->left=new Node(2);              //                                / \*
    // root->right=new Node(6);              //                              2   6
    // root->left->left=new Node(1);        //                              /\*  /\*
    //  root->left->right=new Node(3);      //                             1  3  5 7
    // root->right->left=new Node(5);
    // root->right->right=new Node(7);

    return 0;
}