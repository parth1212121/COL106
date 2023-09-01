#include<iostream>
#include<queue>
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

Node* find(int x,Node* root){                             // elegance......

    if(root==NULL){
        return NULL;
    }
                                                              // O(no of nodes)
    queue<Node*> q;

    q.push(root);
    q.push(NULL);


    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            if(node->data==x){
                return node;
            }
            //cout<<node->data<<" ";
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
        }
        else{
            if(!q.empty()){
              //  cout<<endl;
                q.push(NULL);
            }
        }
    }
}
void removell(Node* &n,Node* &root){
     
    if(n->left==NULL && n->right==NULL){
        n=NULL;
    }
    else if(n->left){
        n->data=n->left->data;
        removell(n->left,root);
    }
    else if(n->right){
        n->data=n->right->data;
        removell(n->right,root);
    }
}
void remove(int x,Node* root){
    Node* n=find(x,root);
    removell(n,root);
    return;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}



int main(){                                                                 // Our Tree.....

    Node* root= new Node(1);             //                                 1
    root->left=new Node(2);              //                                / \*
    root->right=new Node(3);              //                              2   3
    root->left->left=new Node(4);        //                              /\*  /\*
    root->left->right=new Node(5);      //                             4  5  6 7
    root->right->left=new Node(6);        //                          /\*    
    root->right->right=new Node(7);//                                9  10
    root->left->left->left=new Node(9);
    root->left->left->right=new Node(10);
   
    preorder(root);  
    remove(4,root);
    cout<<endl;
    preorder(root);

    return 0;
}