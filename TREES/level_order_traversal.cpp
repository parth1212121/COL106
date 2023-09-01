#include<iostream>
#include<queue>
using namespace std;                                           // BFS.

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

void printLevelOrder(Node* root){                             // elegance......

    if(root==NULL){
        return ;
    }
                                                              // O(no of nodes)
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
        }
        else{
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
            }
        }
    }
}

int main(){

    Node* root= new Node(1);             //                                 1
    root->left=new Node(2);              //                                / \*
    root->right=new Node(3);              //                              2   3
    root->left->left=new Node(4);        //                              /\*  /\*
    root->left->right=new Node(5);      //                             4  5  6 7
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    printLevelOrder(root);

    return 0;
}