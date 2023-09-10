#include<iostream>
#include<stack>

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
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){                                     // Model the call stack.......
        Node* n=st.top();
        st.pop();
        cout<<n->data<<" ";
        if(n->right){
        st.push(n->right);}
        if(n->left){
        st.push(n->left);}
    }
}

int main(){                                                                 // Our Tree.....

    Node* root= new Node(1);             //                                 1
    root->left=new Node(2);              //                                / \*
    root->right=new Node(3);              //                              2   3
    root->left->left=new Node(4);        //                              /\*  /\*
     root->left->right=new Node(5);      //                             4  5  6 7
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    preorder(root);
    cout<<endl;
  
    return 0;
}