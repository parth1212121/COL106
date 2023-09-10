#include<iostream>
using namespace std;
class Node{

    public:

    int data;
    Node* left;
    Node* right;

   Node(int val){
    data=val;
    left=NULL;
    right=NULL;
   } 
};
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


int main(){                                                                 // Our Tree.....

    Node* root= new Node(10);             //                                 1
    root->left=new Node(7);              //                                / \*
    root->right=new Node(13);              //                              2   3
    root->left->left=new Node(3); 
    root->left->left->left=new Node(1); 
    root->left->left->right=new Node(4); 
     root->left->right=new Node(9);      //                             4  5  6 7
    root->right->left=new Node(11);
    root->right->right=new Node(15);
    root->right->right->left=new Node(14);
    root->right->right->right=new Node(18);
    root->right->right->right->left=new Node(17);
    root->right->right->right->right=new Node(20);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    // postorder(root);
    // cout<<endl;

    
    return 0;
}