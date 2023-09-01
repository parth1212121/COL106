#include<iostream>
using namespace std;
class Node{

    public:
    int data;
    Node* left;
    Node* right;

   Node(int val){      ///*****IMPORTANT*** --->>   // But for a BST in worst case it can take O(n) time (in the case of sorted array if inserted...)
    data=val;
    left=NULL;
    right=NULL;
   } 
};

Node* find(int key,Node* root){                                 // O(log_2_n)

    // searches for the key in the BST rooted at root
    // Returns  the node pointer if found and null o.w

    // Assumes short circuit evaluation of boolean expressions

    while((root!=NULL) && (key!=root->data)){
        if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }

    return root;
}

Node* find_min(Node* root){
    if(root==NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* find_max(Node* root){
    if(root==NULL){
        return NULL;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}




int main(){
    
    Node* root= new Node(4);             //                                 4
    root->left=new Node(2);              //                                / \*
    root->right=new Node(6);              //                              2   6
    root->left->left=new Node(1);        //                              /\*  /\*
     root->left->right=new Node(3);      //                             1  3  5 7
    root->right->left=new Node(5);
    root->right->right=new Node(7);
    cout<<find(2,root)->left->data<<endl;
    
    cout<<find_min(root)->data<<endl;
    cout<<find_max(root)->data<<endl;


    return 0;
}